#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"
#include <time.h>
#include <unistd.h>
#include <conio.h>

int main(void)
{

  system("cls");
  printf("  .----------------.  .----------------.  .----------------.\n");
  printf("| .--------------. || .--------------. || .--------------. |\n");
  printf("| |    ______    | || |  ________    | || |      __      | |\n");
  printf("| |  .' ___  |   | || | |_   ___ `.  | || |     /  \\     | |\n");
  printf("| | / .'   \\_|   | || |   | |   `. \\ | || |    / /\\ \\    | |\n");
  printf("| | | |    ____  | || |   | |    | | | || |   / ____ \\   | |\n");
  printf("| | \\ `.___]  _| | || |  _| |___.' / | || | _/ /    \\ \\_ | |\n");
  printf("| |  `._____.'   | || | |________.'  | || ||____|  |____|| |\n");
  printf("| |              | || |              | || |              | |\n");
  printf("| '--------------' || '--------------' || '--------------' |\n");
  printf("'----------------'  '----------------'  '----------------'  \n");
  printf("\n\nrealisee par : ELYOUSFI Ismail  et  ELMOKHTARI Abir\n");
  printf("\n\n                                                      Encadrant:\n                                                ELHASSOUNY");
  printf("\n\n ------>");
  login();
  data* head=(data*)malloc(sizeof(data));
  head->next=NULL;
  head->prev=NULL;

  read_data(head);

  MENU(head);

  save_data(head);

}
