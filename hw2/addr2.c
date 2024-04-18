#include <stdio.h>
#include <stdlib.h>   // Necessary for exit()
#include "backend2.h"     

#define WELCOME_MESSAGE "Welcome to Address Book!\n"
#define COMMAND_PROMPT "ADDR>"
#define ADD_PROMPT "ADD NAME>>"
#define SEARCH_PROMPT "SEARCH NAME>>"
#define NUMBER_PROMPT "ENTER NUMBER>>>"
#define DELETE_PROMPT "DELETE NAME>>"

int prompt_command(char *, char *);
int prompt_name(char *, char *);
int prompt_number(char *, char *);

int main()
{

  char command[1];
  char name[3], number[4];

  printf(WELCOME_MESSAGE);

  while (1) {
  restart:
    if (prompt_command(COMMAND_PROMPT, command) != 0 )
      goto restart;
    switch (command[0]) {
    case 'A':
    case 'a':
      if (prompt_name(ADD_PROMPT, name) !=0)
        goto restart;
      if (prompt_number(NUMBER_PROMPT, number) !=0)
        goto restart;
      add(name, number);
      break;
    case 'S':
    case 's':
      if (prompt_name(SEARCH_PROMPT, name) !=0)
        goto restart;
      search(name);
      break;
    case 'D':
    case 'd':
       if (prompt_name(DELETE_PROMPT, name) !=0)
        goto restart;
      delete(name);
      break;
    case 'Q':
    case 'q':
      printf("Quitting ... \n");
      return 0;
    case 'P':
    case 'p':
      print_list();
      break;
// A new command 'T' and 't' here.
//
      
    default:
      printf("Please enter a valid command.\n");
      goto restart;
    }
  }
}


int prompt_command(char *s, char *p)
{

  char *q;
  char c;

  while (1) {
    printf("%s ", s);
    fflush(stdout);
    q=p;
    while (1) {
      c=getchar();
      if (c==EOF)
        exit(-1);      // Should let exit() take care of the sudden EOF.
      if (c=='\n')     
        break;
      if (q<p+1)
        *q=c;
      q++;
    }
    if (q==p+1)
      return 0;   // got a good command //
    if (q==p)
      return 1;   // just a <return>  //
    printf("Please type a command.\n");
  }
}


int prompt_name(char *s, char *p)
{

  char *q;
  char c;

  while (1) {
    printf("%s ", s);
    fflush(stdout);
    q=p;
    while (1) {
      c=getchar();
      if (c==EOF)
        exit(-1);      // Should let exit() take care of the sudden EOF.
      if (c=='\n')
        break;
      if (q<p+3)
        *q=c;
      q++;
    }
    if (q==p+3)
      return 0;   // got a good name //
    if (q==p)
      return 1;   // just a <return>  //
    printf("Please type a three-letter name.\n");
  }
}


int prompt_number(char *s, char *p)
{
  char *q;
  char c;

  while (1) {
    printf("%s ", s);
    fflush(stdout);
    q=p;
    while (1) {
      c=getchar();
      if (c==EOF)
        exit(-1);            // Should let exit() take care of the sudden EOF.
      if (c=='\n')
        break;
      if (q<p+4)
        *q=c;
      q++;
    }
    if (q==p+4)
      return 0;   // got a good number //
    if (q==p)
      return 1;   // just a <return>  //
    printf("Please type a four-digit number.\n");
  }
  return 0;
}


