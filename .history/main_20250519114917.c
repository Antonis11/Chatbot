#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

FILE *file1;

void learn(int i, char *g1);
void already_know(int i, char *g1);
struct gList *insert(struct gList *sPtr, struct gList g);
int search(struct gList *sPtr, char *con);

typedef struct gList {
  char *concept; // the concept learned
  char *sentence; // the sentence associated with the concept
  int timesUsed; //no of times the concept was used to an answer
  char learnedFrom[5]; //learned either from "file" or "kbrd"
  struct gList *next;
  struct gList *prev;
} gtpList;

void learn(int i, char *g1)
{
    fprintf(file1,"ChatGTP$ ");
    if(i==1) {
        printf("I learned about %s. Now stop bugging me!\n",g1);
        fprintf(file1,"I learned about %s. Now stop bugging me!\n",g1);
    }
    else if (i==2) {
        printf("Wow! First time I learn something about %s!\n",g1);
        fprintf(file1,"Wow! First time I learn something about %s!\n",g1);
    }
    else if (i==3) {
        printf("Learning about %s was very interesting! (no it wasn’t, I was just being polite)\n",g1);
        fprintf(file1,"Learning about %s was very interesting! (no it wasn’t, I was just being polite)\n",g1);
    }
    else if (i==4) {
        printf("%s sounds interesting! Glad to have learned about it...\n",g1);
        fprintf(file1,"%s sounds interesting! Glad to have learned about it...\n",g1);
    }
    else if (i==5) {
        printf("Learning about %s was a piece of cake...\n",g1);
        fprintf(file1,"Learning about %s was a piece of cake...\n",g1);
    }
}

void already_know(int i, char *g1) {
    fprintf(file1,"ChatGTP$ ");
    if(i==1) {
        printf("Do you honestly believe I'm an imbecile? I've been acquainted with the legend of %s long before your existence on this Earth\n",g1);
        fprintf(file1,"Do you honestly believe I'm an imbecile? I've been acquainted with the legend of %s long before your existence on this Earth\n",g1);
    }
    else if (i==2) {
        printf("I already know about %s!\n",g1);
        fprintf(file1,"I already know about %s!\n",g1);
    }
    else if (i==3) {
        printf("Do you think I am a moron? I knew about %s before you were even born!\n",g1);
        fprintf(file1,"Do you think I am a moron? I knew about %s before you were even born!\n",g1);
    }
    else if (i==4) {
        printf("Is it possible that you perceive me as an idiot? My knowledge of %s predates your birth by a significant margin.\n",g1);
        fprintf(file1,"Is it possible that you perceive me as an idiot? My knowledge of %s predates your birth by a significant margin.\n",g1);
    }
    else if (i==5) {
        printf("I learned about %s\n",g1);
        fprintf(file1,"I learned about %s\n",g1);
    }
}

struct gList *insert(struct gList *sPtr, struct gList g) {

 struct gList *new, *previousPtr, *currentPtr;

    new = (struct gList *) malloc(sizeof(struct gList));
    if (new == NULL) {
        printf("Concept %s is not inserted. No memory available\n", g.concept);
    }
    else {
        new->concept = strdup(g.concept);
        new->sentence = strdup(g.sentence);
        new->timesUsed = g.timesUsed;
        strcpy(new->learnedFrom, g.learnedFrom);
        new->next = NULL;
        new->prev = NULL;

        if (sPtr == NULL) {
            sPtr = new;
        }
        else {
            previousPtr = NULL;
            currentPtr = sPtr;
            while ((currentPtr != NULL) && strcmp(new->concept, currentPtr->concept)>0) {
                previousPtr = currentPtr;
                currentPtr = currentPtr->next;
            }

            if ( previousPtr == NULL ) {
                new->next = sPtr;
                sPtr = new;
            }
            else {
                previousPtr->next = new;
                new->next = currentPtr;
            }

            /* if(previous == NULL) {
                sPtr = new;
            }
            else {
                previousPtr->next = new;
                new->prev = previousPtr;
            }

            if(currentPtr != NULL) {
                currentPtr->prev = new;
            }

            new->next = currentPtr; */

        }
    }
    return sPtr;
}

int search(struct gList *currentPtr, char *con) {

    if(currentPtr == NULL)
        return 0;

    while (currentPtr != NULL) {
        if(strcmp(currentPtr->concept,con) == 0) {
            return 1;
        }
        if (strcmp(currentPtr->concept,con)>0) {
            currentPtr = currentPtr->prev;
        }
        else {
            currentPtr = currentPtr->next;
        }
    }
    return 0;
}

int main(void) {
    char *text, *text1;
    struct gList tmp, *head = NULL;
    int i, len, j;

    while(1) {
        printf("\033[1;30mme$ \033[0m");
        fgets(text,10000,stdin);

        fprintf(file1,"me$ ");

        len = strlen(text);
        //printf("%d\n",len);

        for(i=0;i<13;i++){ //12
            strncat(text1,&text[i],1);
        }
        //printf("%s\n", text1);
        fprintf(file1,"%s",text);
    
        if(strncmp(text1,"learn this > ",12) == 0) {

            tmp.timesUsed=0;
            strcpy(tmp.learnedFrom,"kbrd");

            tmp.concept = (char*) malloc (sizeof(char) * 100);
            if ( tmp.concept == NULL ) {
                exit(EXIT_FAILURE);
            }
            strcpy(tmp.concept, "");

            for(i=13;i<len;i++) {
                if(text[i] != ':') {
                    j=i;
                    strncat(tmp.concept,&text[i],1);
                }
                else if(text[i] == ':')
                    break;
            }
            //printf("Con: %s\n", tmp.concept);

            tmp.sentence = (char*) malloc (sizeof(char) * 10000);
            if ( tmp.sentence == NULL ) {
                exit(EXIT_FAILURE);
            }

            // printf("J: %d\n",j);

            for(j=i+2;j<len;j++) {
                strncat(tmp.sentence,&text[j],1);
            }
            //printf("Sen: %s\n",tmp.sentence);

            if( search(head,tmp.concept) == 1 ) {
                printf("\033[1;30mChatGTP$ \033[0m");
                i = rand() % 5 + 1;
                already_know(i,tmp.concept);
            }
            else if( search(head,tmp.concept) == 0 ) {
                printf("\033[1;30mChatGTP$ \033[0m");
                i = rand() % 5 + 1;
                learn(i,tmp.concept);
                head = insert(head,tmp);
                printList(head);
            }
            strcpy(text, "");
            strcpy(text1, "");

        }
    }
    return 0;
}    
