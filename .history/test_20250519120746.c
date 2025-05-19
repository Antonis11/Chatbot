#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

FILE *file1;

void learn(int i, char *g1);
void already_know(int i, char *g1);
void delete_term(int i, char *g1);
void not_delete(int i, char *g1);
void general_answer(int i);
void dont_know(int i, char *g1);
struct gList *insert(struct gList *sPtr, struct gList g);
int delete(struct gList **sPtr,struct gList g);
int delete1(struct gList **sPtr, struct gList g);
int search(struct gList *sPtr, char *con);
char *search1(struct gList *currentPtr, char *con);
char *search2(struct gList *currentPtr, char *con);
void printList( struct gList *currentPtr );
void printConcept( struct gList *currentPtr );
void times_Used( struct gList *currentPtr );
void freeList(struct gList *head);

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

void delete_term(int i, char *g1) {
 fprintf(file1,"ChatGTP$ ");
 if(i==1) {
  printf("%s turned out to be useless, so I forgot it :)\n",g1);
  fprintf(file1,"%s turned out to be useless, so I forgot it :)\n",g1);
 }
 else if (i==2) {
  printf("%s proved to be pointless, so it slipped right out of my mind.\n",g1);
  fprintf(file1,"%s proved to be pointless, so it slipped right out of my mind.\n",g1);
 }
 else if (i==3) {
  printf("%s ended up being a useless skill, so I erased it from my memory.\n",g1);
  fprintf(file1,"%s ended up being a useless skill, so I erased it from my memory.\n",g1);
 }
 else if (i==4) {
  printf("I found no use for %s, so I promptly forgot all about it.\n",g1);
  fprintf(file1,"I found no use for %s, so I promptly forgot all about it.\n",g1);
 }
 else if (i==5) {
  printf("%s proved to be of no practical value, so I quickly let it fade away from my memory.\n",g1);
  fprintf(file1,"%s proved to be of no practical value, so I quickly let it fade away from my memory.\n",g1);
 }
}

void not_delete(int i, char *g1) {
 fprintf(file1,"ChatGTP$ ");
 if(i==1) {
  printf("What is %s? I cannot forget something I don’t know!\n",g1);
  fprintf(file1,"What is %s? I cannot forget something I don’t know!\n",g1);
 }
 else if (i==2) {
  printf("Who is %s? I can't remember something I've never learned about!\n",g1);
  fprintf(file1,"Who is %s? I can't remember something I've never learned about!\n",g1);
 }
 else if (i==3) {
  printf("Can you tell me about %s? It's hard to forget something when I have no knowledge of it.\n",g1);
  fprintf(file1,"Can you tell me about %s? It's hard to forget something when I have no knowledge of it.\n",g1);
 }
 else if (i==4) {
  printf("What can you tell me about %s? It's difficult to forget something when I don't have any information about it.\n",g1);
  fprintf(file1,"What can you tell me about %s? It's difficult to forget something when I don't have any information about it.\n",g1);
 }
 else if (i==5) {
  printf("I'm curious about %s. It's impossible to forget something I've never been aware of!\n",g1);
  fprintf(file1,"I'm curious about %s. It's impossible to forget something I've never been aware of!\n",g1);
 }
}

void general_answer(int i) {
 fprintf(file1,"ChatGTP$ ");
 if(i==1) {
  printf("You are absolutely right!\n");
  fprintf(file1,"You are absolutely right!\n");
 }
 else if (i==2) {
  printf("It seems that what you say is reasonable\n");
  fprintf(file1,"It seems that what you say is reasonable\n");
 }
 else if (i==3) {
  printf("Your statement appears to be logical and sound.\n");
  fprintf(file1,"Your statement appears to be logical and sound.\n");
 }
 else if (i==4) {
  printf("What you're saying sounds like a reasonable argument.\n");
  fprintf(file1,"What you're saying sounds like a reasonable argument.\n");
 }
 else if (i==5) {
  printf("I completely agree with you!\n");
  fprintf(file1,"I completely agree with you!\n");
 }
}

void dont_know(int i, char *g1) {
 fprintf(file1,"ChatGTP$ ");
 if(i==1) {
  printf("Sorry, I know nothing about %s.\n",g1);
  fprintf(file1,"Sorry, I know nothing about %s.\n",g1);
 }
 else if (i==2) {
  printf("Apologies, I have no knowledge or experience when it comes to understanding %s.\n",g1);
  fprintf(file1,"Apologies, I have no knowledge or experience when it comes to understanding %s.\n",g1);
 }
 else if (i==3) {
  printf("I'm afraid I can't offer any insights or information about %s.\n",g1);
  fprintf(file1,"I'm afraid I can't offer any insights or information about %s.\n",g1);
 }
 else if (i==4) {
  printf("I don't know about %s\n",g1);
  fprintf(file1,"I don't know about %s\n",g1);
 }
 else if (i==5) {
  printf("I haven't learned about %s\n",g1);
  fprintf(file1,"I haven't learned about %s\n",g1);
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

int delete(struct gList **sPtr, struct gList g)
{
   struct gList *previousPtr, *currentPtr, *tempPtr;

   if(strcmp(g.concept,(*sPtr)->concept) == 0) {
      tempPtr = *sPtr;
      *sPtr = (*sPtr)->next;  /* de-thread the node */
      if (*sPtr != NULL) {
         (*sPtr)->prev = NULL;
      }
     free(tempPtr);             /* free the de-threaded node */
      return 1;
   }
   else {
      previousPtr = NULL; // *sPtr;
      currentPtr = (*sPtr); //->next;

      while ( (currentPtr != NULL) && (strcmp(currentPtr->concept,g.concept) != 0 ) ) {
         previousPtr = currentPtr;          /* walk to ...   */
         currentPtr = currentPtr->next;  /* ... next node */
      }

      if ( (currentPtr != NULL) && (strcmp(currentPtr->concept,g.concept) == 0 ) ) {
         tempPtr = currentPtr;
         previousPtr->next = currentPtr->next;
         if (currentPtr->next != NULL) {
            currentPtr->next->prev = previousPtr;
         }
         free(tempPtr);
         return 1;
      }
   }

   return 0;
}

int delete1(struct gList **sPtr, struct gList g)
{
   struct gList *previousPtr, *currentPtr, *tempPtr;

   if(strcasestr(g.concept,(*sPtr)->concept)!=0) {
      tempPtr = *sPtr;
      *sPtr = (*sPtr)->next;  /* de-thread the node */
      if (*sPtr != NULL) {
         (*sPtr)->prev = NULL;
      }
     free(tempPtr);             /* free the de-threaded node */
      return 1;
   }
   else {
      previousPtr = NULL; // *sPtr;
      currentPtr = (*sPtr); //->next;

      while ( (currentPtr != NULL) && (strcasestr(currentPtr->concept,g.concept) == 0 ) ) { //!=
         previousPtr = currentPtr;          /* walk to ...   */
         currentPtr = currentPtr->next;  /* ... next node */
      }

      if ( (currentPtr != NULL) && (strcasestr(currentPtr->concept,g.concept) != 0 ) ) {
         tempPtr = currentPtr;
         previousPtr->next = currentPtr->next;
         if (currentPtr->next != NULL) {
            currentPtr->next->prev = previousPtr;
         }
         free(tempPtr);
         return 1;
      }
   }

   return 0;
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

char *search1(struct gList *currentPtr, char *con) {

  if(currentPtr == NULL)
    return NULL;

    while (currentPtr != NULL) {
        if(strcasestr(currentPtr->concept,con) != 0) {
            return currentPtr->concept;
        }
       if (strcmp(currentPtr->concept,con)>0) {
            currentPtr = currentPtr->prev;
        }
        else {
            currentPtr = currentPtr->next;
        }
    }
    return NULL;
}

char *search2(struct gList *currentPtr, char *con) {

  if(currentPtr == NULL)
    return NULL;

    while (currentPtr != NULL) {
        if(strcasestr(currentPtr->concept,con) != 0) { //==0
            currentPtr->timesUsed +=1;
            return currentPtr->sentence;
        }
       if (strcmp(currentPtr->concept,con)>0) {
            currentPtr = currentPtr->prev;
        }
        else {
            currentPtr = currentPtr->next;
        }
    }
    return NULL;
}

void printList( struct gList *currentPtr ) {
   if ( currentPtr == NULL )
      printf( "List is empty.\n\n" );
   else {
      printf( "The list is:\n" );
      //printf( "NULL <-->" );
      while ( currentPtr != NULL ) {
         printf( "%s\n", currentPtr->concept );
         printf( "%s\n", currentPtr->sentence );
         printf( "%d\n", currentPtr->timesUsed );
         printf( "%s\n\n", currentPtr->learnedFrom );
         currentPtr = currentPtr->next;
      }
      //printf( "NULL\n\n" );
   }
}

void printConcept( struct gList *currentPtr ) {
   if ( currentPtr == NULL )
      printf( "I don't know any Concept(s).\n" );
   else {
      printf( "The Concept(s) i know is:\n" );
      while ( (currentPtr != NULL) ) {
         printf( "%s\n", currentPtr->concept );
         printf("%d\n", currentPtr->timesUsed);
         fprintf(file1, "%s\n", currentPtr->concept );
         fprintf(file1, "%d\n", currentPtr->timesUsed );
         currentPtr = currentPtr->next;
      }
   }
}

void times_Used( struct gList *currentPtr ) {
   if ( currentPtr == NULL )
      printf( "No one Concept has timesUsed higher than 0.\n" );
   else {
      printf( "The Concept(s) which has timesUsed higher than 0 is:\n" );
      while ( currentPtr != NULL ) {
         if(currentPtr->timesUsed >0) {
          printf( "%s\n", currentPtr->concept );
          fprintf(file1, "%s\n", currentPtr->concept );
         }
         currentPtr = currentPtr->next;
      }
   }
}

void freeList(struct gList *head) {
    struct gList *current = head;
    while (current != NULL) {
        struct gList *temp = current;
        current = current->next;
        free(temp->concept);
        free(temp->sentence);
        free(temp);
    }
}

int main(void){
 char *text,*text1,*text2,*line;
 struct gList tmp, *head = NULL;
 int i,len,j,k,pl;
 FILE *file;

 srand(time(NULL));

 text = (char*) malloc(sizeof(char) * 10000);
 if(text == NULL) {
    printf("No memmory available!!!\n");
    exit(1);
 }

 text1 = (char*) malloc(sizeof(char) * 100);
 if(text1 == NULL) {
   printf("No memmory available!!!\n");
   exit(1);
 }

 file1 = fopen("dialogue.txt", "w");
 if (file1 == NULL) {
   printf("File dialogue.txt cannot be opened!!!\n");
 }

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

  for(i=13;i<len;i++)
  {
   if(text[i] != ':')
   {
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

  for(j=i+2;j<len;j++)
  {
    strncat(tmp.sentence,&text[j],1);
  }
  //printf("Sen: %s\n",tmp.sentence);

  if( search(head,tmp.concept) == 1 )
  {
    printf("\033[1;30mChatGTP$ \033[0m");
    i = rand() % 5 + 1;
    already_know(i,tmp.concept);
  }
  else if( search(head,tmp.concept) == 0 )
  {
    printf("\033[1;30mChatGTP$ \033[0m");
    i = rand() % 5 + 1;
    learn(i,tmp.concept);
    head = insert(head,tmp);
    printList(head);
  }
  strcpy(text, "");
  strcpy(text1, "");

 }
 else if(strncmp(text1,"read this > ",11) == 0) {

  tmp.timesUsed=0;
  strcpy(tmp.learnedFrom,"file");

  text2 = (char*) malloc(sizeof(char) * 100);
  if(text2 == NULL) {
   printf("No memmory available!!!\n");
   exit(1);
  }

  for(i=12;i<len-1;i++){
    strncat(text2,&text[i],1);
  }
  printf("%s\n", text2);

  tmp.concept = (char*) malloc (sizeof(char) * 100);
  if ( tmp.concept == NULL ) {
     exit(EXIT_FAILURE);
  }

  tmp.sentence = (char*) malloc (sizeof(char) * 10000);
  if ( tmp.sentence == NULL ) {
    exit(EXIT_FAILURE);
  }

    file = fopen(text2, "r");
    if (file == NULL) {
        printf("Are you stupid mate? How am I supposed to find file %s unless you put it in the correct place?\n",text2);
    }
    else {
           printf("\033[1;30mChatGTP$ \033[0m");
           printf("File %s was a pleasure to read...\n",text2);
           fprintf(file1,"File %s was a pleasure to read...\n",text2);


    line = (char*) malloc (sizeof(char) * 10000);
    if ( line == NULL ) {
     exit(EXIT_FAILURE);
    }

    while(fgets(line, 10000 , file)) {
        sscanf(line, "%[^:]: %[^\n]", tmp.concept, tmp.sentence);
        if(search(head,tmp.concept) == 1)
        {
         printf("\033[1;30mChatGTP$ \033[0m");
         i = rand() % 5 + 1;
         already_know(i,tmp.concept);
        }
        else if(search(head,tmp.concept) == 0)
        {
         printf("\033[1;30mChatGTP$ \033[0m");
         i = rand() % 5 + 1;
         learn(i,tmp.concept);
         head = insert(head,tmp);
         printList(head);
        }
    } //end while
    fclose(file);
    strcpy(text, "");
    strcpy(text1, "");
    strcpy(text2, "");
   }

 }//end else if

 else if(strncmp(text1,"forget this > ",13) == 0) {

  tmp.concept = (char*) malloc (sizeof(char) * 100);
  if ( tmp.concept == NULL ) {
    exit(EXIT_FAILURE);
  }
  strcpy(tmp.concept, "");

  k=0;
  for(i=14;i<len;i++)
  {
   if( (text[i] != ',') && (text[i] != '.') )
   {
    strncat(tmp.concept,&text[i],1);
   }
   else if(text[i] == ',') {

     tmp.concept[strcspn(tmp.concept,"\n")]='\0';

     if(search1(head,tmp.concept) != NULL)  //Evrica
     {
      printf("\033[1;30mChatGTP$ \033[0m");
      k = rand() % 5 + 1;
      delete_term(k,search1(head,tmp.concept));
      delete1(&head,tmp);
      printList(head);
      i++;
      strcpy(tmp.concept, "");
     }
         else if(search1(head,tmp.concept) == NULL)  //Den Evrica
     {
      printf("\033[1;30mChatGTP$ \033[0m");
      k = rand() % 5 + 1;
      not_delete(k,tmp.concept);
      delete1(&head,tmp);
      printList(head);
      i++;
      strcpy(tmp.concept, "");
     }
  } //end else if
  else if(text[i] == '.') {
     tmp.concept[strcspn(tmp.concept,"\n")]='\0';

     if(search1(head,tmp.concept) != NULL)  //Evrica
     {
      printf("\033[1;30mChatGTP$ \033[0m");
      k = rand() % 5 + 1;
      delete_term(k,search1(head,tmp.concept));
      delete1(&head,tmp);
      printList(head);
      strcpy(tmp.concept, "");
      //break;
     }
     else if(search1(head,tmp.concept) == NULL)  //Den Evrica
     {
      printf("\033[1;30mChatGTP$ \033[0m");
      k = rand() % 5 + 1;
      not_delete(k,tmp.concept);
      delete1(&head,tmp);
      printList(head);
      strcpy(tmp.concept, "");
      //break;
     }
  }
 } //end for
  strcpy(text, "");
  strcpy(text1, "");
 }
 else if(strncmp(text,"What is the meaning of Life, The Universe, and Everything?",57) == 0) {
  printf("\033[1;30mChatGTP$ \033[0m");
  printf("42\n");
  fprintf(file1,"ChatGTP$ ");
  fprintf(file1,"42\n");
  strcpy(text, "");
  strcpy(text1, "");
 }
 else if(strncmp(text,"What do you know about?",22) == 0 ) {
   printf("\033[1;30mChatGTP$ \033[0m");
   fprintf(file1,"ChatGTP$ ");
   printConcept(head);
   strcpy(text, "");
   strcpy(text1, "");
 }
 else if(strncmp(text,"What do you talk about?",22) == 0 ) {
   printf("\033[1;30mChatGTP$ \033[0m");
   fprintf(file1,"ChatGTP$ ");
   times_Used(head);
   strcpy(text, "");
   strcpy(text1, "");
 }
 else if(strncmp(text,"So Long, and Thanks for All the Fish",35) == 0) {
  printf("\033[1;30mChatGTP$ \033[0m");
  printf("Can't say i enjoyed this conversasion. Bye!\n");
  printf("Save in file dialogue.txt\n");
  fclose(file1);
  return 0;
 }
 else if( (text[len-2]== '.') ){
  printf("\033[1;30mChatGTP$ \033[0m");
  i = rand() % 5 + 1;
  general_answer(i);
  strcpy(text, "");
  strcpy(text1, "");
 }
 else if(text[len-2]== '?'){

 tmp.concept = (char*) malloc (sizeof(char) * 100);
 if ( tmp.concept == NULL ) {
   exit(EXIT_FAILURE);
 }
 strcpy(tmp.concept, "");

 for(i=0;i<len;i++)
 {
   if( (text[i] == '*') )
   {
    for(j=i+1;j<len-2;j++) {
     if( (text[j] == '*')  ){
      break;
     }
     else {
      strncat(tmp.concept,&text[j],1);
     }
    }
   }
 }

 tmp.concept[strcspn(tmp.concept,"\n")]='\0';

 if(search1(head,tmp.concept) != NULL)  //Evrica
 {
  printf("\033[1;30mChatGTP$ \033[0m");
  fprintf(file1,"ChatGTP$ ");
  printf("%s\n",search2(head,tmp.concept));
  fprintf(file1,"%s\n",search2(head,tmp.concept));
  printList(head);
  strcpy(tmp.concept, "");
  }
  else if(search1(head,tmp.concept) == NULL)  //Den Evrica
  {
   printf("\033[1;30mChatGTP$ \033[0m");
   k = rand() % 5 + 1;
   dont_know(k,tmp.concept);
   printList(head);
   strcpy(tmp.concept, "");
   }
  strcpy(text, "");
  strcpy(text1, "");
 }
 else {
  strcpy(text, "");
  strcpy(text1, "");
 }
}//end while(1)

 freeList(head);
 free(text);
 free(text1);
 free(text2);

return 0;
}

