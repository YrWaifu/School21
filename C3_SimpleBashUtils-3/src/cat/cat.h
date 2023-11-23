#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAXLEN 1000

typedef struct options {
  int b, e, n, s, t;
  char *filename;
} options;

void printErrorMessage(int error);
void printB(int *countLines, int countCurrLines, char line[4096]);
void printN(int *countLines, int countCurrLines, char line[4096]);
void printBE(int *countLines, int countCurrLines, char line[4096]);
int getOption(char curOpt, options *opt);
int processing(options *opt, int *countLines, int *flag);
void goingThroughLines(options *opt, FILE *file, const int *error,
                       int *countLines, int *flag);
int main(int argc, char *argv[]);