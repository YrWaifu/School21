#include "grep.h"

void printErrorMessage(int error) {
  if (error == 1) {
    printf("Invalid option\n");
  } else if (error == 2) {
    printf("File doesn't exist\n");
  } else if (error == 3) {
    printf("Too few arguments\n");
  } else if (error == 4) {
    printf("Error compiling regex\n");
  }
}

int getOption(char curOpt, options *opt, char *optarg) {
  int error = 0;
  if (curOpt == 'e') {
    strncpy(opt->ePatterns[opt->e], optarg, sizeof(opt->ePatterns[0]));
    opt->e += 1;
  } else if (curOpt == 'i') {
    opt->i = 1;
  } else if (curOpt == 'v') {
    opt->v = 1;
  } else if (curOpt == 'c') {
    opt->c = 1;
  } else if (curOpt == 'l') {
    opt->l = 1;
  } else if (curOpt == 'n') {
    opt->n = 1;
  } else if (curOpt == 'h') {
    opt->h = 1;
  } else if (curOpt == 's') {
    opt->s = 1;
  } else if (curOpt == 'f') {
    opt->f = 1;
    error = fOption(opt, optarg);
  } else if (curOpt == 'o') {
    opt->o = 1;
  } else if (opt->e == 0 && optarg != NULL && opt->f == 0) {
    strncpy(opt->ePatterns[opt->e], optarg, sizeof(opt->ePatterns[0]));
    opt->e += 1;
  } else {
    error = 1;
  }
  return error;
}

int searchAndPrintAllMatches(options *opt) {
  int error = 0;
  FILE *file = fopen(opt->filename, "r");
  error = (file == NULL) ? 2 : 0;
  if (error == 0) {
    goingThroughLines(opt, file, &error);
  }
  if (error != 2) {
    fclose(file);
  }
  return error;
}

int printOnScreen(options *opt, int countLines, char *template, char *line,
                  int countOcc) {
  if (opt->n != 0) {
    printf("%d:", countLines);
  }
  if (opt->o) {
    for (int i = 0; i < countOcc; i++) {
      if (i != 0) {
        printFilename(opt);
      }
      printf("%s\n", template);
    }
  } else {
    printf("%s", line);
  }
  return 0;
}

int numberOfOcc(char line[4096], pcre *re) {
  int count = 0, rc, offset = 0, ovector[30];
  while ((rc = pcre_exec(re, NULL, line, strlen(line), offset, 0, ovector,
                         30)) >= 0) {
    count += 1;
    offset = ovector[1];
  }
  return count;
}

void goingThroughLines(options *opt, FILE *file, int *error) {
  pcre *re;
  const char *reerror;
  int erroffset, countLines = 0, correctLines = 0, foundInFile = 0;
  char line[4096];
  while (file != NULL && (fgets(line, sizeof(line), file) != NULL) &&
         (*error == 0)) {
    countLines += 1;
    int almostDone = 0;
    for (int i = 0; (i < opt->e) && (*error == 0); i++) {
      re = pcre_compile(opt->ePatterns[i], opt->i ? PCRE_CASELESS : 0, &reerror,
                        &erroffset, NULL);
      int ovector[30];
      *error = (re == NULL) ? 4 : 0;
      int rc = pcre_exec(re, NULL, line, strlen(line), 0, 0,
                         opt->i ? ovector : NULL, opt->i ? 30 : 0);
      if (rc >= 0 && opt->v == 0 && opt->c == 0 && opt->l == 0 &&
          almostDone == 0) {
        printFilename(opt);
        printOnScreen(opt, countLines, opt->ePatterns[i], line,
                      numberOfOcc(line, re));
        correctLines += 1, almostDone += 1;
      } else if (opt->v != 0 && rc < 0 && opt->c == 0 && almostDone == 0) {
        printFilename(opt);
        printOnScreen(opt, countLines, opt->ePatterns[i], line,
                      numberOfOcc(line, re));
        correctLines += 1, almostDone += 1;
      }
      correctLines += (rc >= 0 && opt->v == 0) ? 1 : 0;
      correctLines += (opt->v != 0 && rc < 0) ? 1 : 0;
      pcre_free(re);
    }
  }
  if (*error == 0) {
    if (opt->c != 0 && opt->l == 0) {
      printFilename(opt);
      printf("%d\n", correctLines);
    }
  }
  foundInFile += (correctLines > 0) ? 1 : 0;
  if (foundInFile && opt->l != 0) {
    printf("%s\n", opt->filename);
  }
}

void printFilename(options *opt) {
  if (opt->moreThanOneFile && opt->h == 0) {
    printf("%s:", opt->filename);
  }
}

int fOption(options *opt, const char *filename) {
  FILE *file = fopen(filename, "r");
  int error = 0;
  if (!file) {
    error = 2;
  }

  char line[MAXPATTERNS];
  int patternCount = 0;
  while (file != NULL && (fgets(line, sizeof(line), file) != NULL) &&
         (error == 0)) {
    size_t length = strlen(line);
    if (length > 0 && line[length - 1] == '\n') {
      line[length - 1] = '\0';
    }

    strncpy(opt->ePatterns[opt->e + patternCount], line,
            sizeof(opt->ePatterns[0]));
    patternCount++;
  }
  opt->e += patternCount;
  if (file != NULL) {
    fclose(file);
  }

  return error;
}

int main(int argc, char *argv[]) {
  int curOpt = 0, error = 0;
  options opt;
  opt.c = 0, opt.e = 0, opt.i = 0, opt.l = 0, opt.n = 0, opt.v = 0, opt.s = 0,
  opt.h = 0, opt.f = 0, opt.o = 0, opt.moreThanOneFile = 0;
  opt.filename = NULL;
  while (((curOpt = getopt(argc, argv, "e:ivclnhsf:o")) != -1) &&
         (error == 0)) {
    error = getOption(curOpt, &opt, optarg);
  }
  if (argc < 3) {
    error = 3;
  }
  for (int i = 1; i < argc && error == 0; ++i) {
    if (argv[i][0] != '-' && i != argc - 1 &&
        (strcmp("-e", argv[i - 1]) != 0) && opt.e == 0) {
      strncpy(opt.ePatterns[opt.e], argv[i], sizeof(opt.ePatterns[0]));
      opt.e += 1;
    } else if (argv[i][0] != '-' && (strcmp("-e", argv[i - 1]) != 0) &&
               opt.e != 0 && error == 0 && (strcmp("-f", argv[i - 1]) != 0)) {
      opt.moreThanOneFile +=
          (i != argc - 1 && opt.moreThanOneFile == 0) ? 1 : 0;
      opt.filename = argv[i];
      error = searchAndPrintAllMatches(&opt);
    }
  }
  // printf("c: %d; i: %d, l: %d, n: %d, v: %d, e: %d, template: %s, filename:
  // %s", opt.c, opt.i, opt.l, opt.n,
  //        opt.v, opt.e, opt.ePatterns[0], opt.filename);
  if (opt.filename == NULL) {
    error = 3;
  }
  if (opt.s == 0) {
    printErrorMessage(error);
  }
  return 0;
}
