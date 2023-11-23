#include "cat.h"

void printErrorMessage(int error) {
  if (error == 1) {
    printf("Invalid option\n");
  } else if (error == 2) {
    printf("File doesn't exist\n");
  } else if (error == 3) {
    printf("Too few arguments\n");
  }
}

int getOption(char curOpt, options *opt) {
  int error = 0;
  if (curOpt == 'b') {
    opt->b += 1;
  } else if (curOpt == 'e') {
    opt->e += 1;
  } else if (curOpt == 'n') {
    opt->n += 1;
  } else if (curOpt == 's') {
    opt->s += 1;
  } else if (curOpt == 't') {
    opt->t += 1;  // Corrected the assignment operator
  } else {
    error = 1;
  }
  return error;
}

// Added function prototype
void goingThroughLines(options *opt, FILE *file, const int *error,
                       int *countLines, int *flag);

int processing(options *opt, int *countLines, int *flag) {
  int error = 0;
  FILE *file = fopen(opt->filename, "r");
  error = (file == NULL) ? 2 : 0;
  if (error == 0) {
    goingThroughLines(opt, file, &error, countLines, flag);
  }
  if (error != 2) {
    fclose(file);
  }
  return error;
}

void goingThroughLines(options *opt, FILE *file, const int *error,
                       int *countLines, int *flag) {
  char line[4096] = "";
  char prevLine[4096] = "";
  char currLine[4096] = "";
  char tempLine[4096] = "";  // Added tempLine buffer
  int len = 0, firstLine = 1;
  while (file != NULL && fgets(line, sizeof(line), file) != NULL &&
         (*error == 0)) {
    strcpy(currLine, line);
    *countLines += (opt->b != 0) ? (strcmp(line, "\n") != 0) ? 1 : 0 : 1;
    *countLines -= (*flag == 1 && firstLine == 1) ? 1 : 0;
    if (opt->s != 0 && strcmp(prevLine, "\n") == 0 &&
        strcmp(currLine, "\n") == 0) {
      *countLines -= 1;
      continue;
    }
    if (opt->b != 0 && strcmp(line, "\n") != 0) {
      if (!(*flag == 1 && firstLine == 1)) {
        sprintf(tempLine, "%6d\t", *countLines);
        strcat(tempLine, line);
        strncpy(line, tempLine, sizeof(line) - 1);
      }
    }
    if (opt->b == 0 && opt->n != 0) {
      if (!(*flag == 1 && firstLine == 1)) {
        sprintf(tempLine, "%6d\t", *countLines);
        strcat(tempLine, line);
        strncpy(line, tempLine, sizeof(line) - 1);
      }
    }
    if (opt->e != 0) {
      len = strlen(line);
      if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '$';
        line[len] = '\n';
        line[len + 1] = '\0';
      }
    }
    if (opt->t != 0) {
      for (size_t j = 0; j < strlen(line); j++) {
        if (line[j] == '\t') {
          line[j] = '^';
          memmove(&line[j + 1], &line[j], strlen(line) - j);
          line[j + 1] = 'I';
        }
      }
    }
    printf("%s", line);
    strcpy(prevLine, currLine);
    firstLine = 0;
  }
  len = strlen(prevLine);
  *flag = (prevLine[len - 1] == '\n' || strlen(prevLine) == 0) ? 0 : 1;
}

int main(int argc, char *argv[]) {
  int curOpt = 0, error = 0, flag = 0;
  options opt;
  opt.b = 0, opt.e = 0, opt.n = 0, opt.s = 0, opt.t = 0;
  opt.filename = NULL;
  int countLines = 0;
  while (((curOpt = getopt(argc, argv, "benst")) != -1) && (error == 0)) {
    error = getOption(curOpt, &opt);
  }
  if (argc < 2) {
    error = 3;
  }

  for (int i = 1; i < argc && error == 0; ++i) {
    if (argv[i][0] != '-') {
      opt.filename = argv[i];
      error = processing(&opt, &countLines, &flag);
    }
  }

  printErrorMessage(error);
  return error;
}
