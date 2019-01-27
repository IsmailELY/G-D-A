#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"
#include <time.h>
#include <unistd.h>

int main(void)
{
  system("cls");
  login();
  data* head=(data*)malloc(sizeof(data));
  head->next=NULL;
  head->prev=NULL;

  MENU(head);

}
