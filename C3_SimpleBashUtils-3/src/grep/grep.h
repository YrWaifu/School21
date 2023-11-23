#include <getopt.h>
#include <pcre.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPATTERNS 100

typedef struct options {
  int e, i, v, c, l, n, h, s, f, o;
  char ePatterns[MAXPATTERNS][MAXPATTERNS];
  char *filename;
  int moreThanOneFile;
} options;

void printErrorMessage(int error);
int getOption(char curOpt, options *opt, char *optarg);
int searchAndPrintAllMatches(options *opt);
int printOnScreen(options *opt, int countLines, char *template, char *line,
                  int countOcc);
int numberOfOcc(char line[4096], pcre *re);
void goingThroughLines(options *opt, FILE *file, int *error);
void printFilename(options *opt);
int fOption(options *opt, const char *filename);
int main(int argc, char *argv[]);