#include <stdio.h>

typedef struct gList {
  char *concept; // the concept learned
  char *sentence; // the sentence associated with the concept
  int timesUsed; //no of times the concept was used to an answer
  char learnedFrom[5]; //learned either from "file" or "kbrd"
  struct gList *next;
  struct gList *prev;
} gtpList;

