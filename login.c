#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"
#include <time.h>
#include <unistd.h>


void login()
{
  char password[20]="Ensias@2009";
  char attempt[20];
  printf("Mot de Passe:\t");
  scanf("%s",&attempt);

  while(strcmp(attempt,password)!=0)
  {
    printf("\amot de passe errone !\nReessayez :\t");
    scanf("%s",&attempt);
  }
}


void close_menu(data*head)
{
  system("cls");
  int N_DATA=0;

  printf("\n############################################################################################\n");
  printf("#                                                                                          #\n");
  printf("#                                                                                          #\n");
  printf("#                       Etes-vous sur de vouloir quitter le Menu ?                         #\n");
  printf("#                                                                                          #\n");
  printf("#                   1)-OUI                                     2)-NON                      #\n");
  printf("#                                                                                          #\n");
  printf("#                                                                                          #\n");
  printf("############################################################################################\n");
  while(N_DATA!=1 && N_DATA!=2)
  {
    printf("\nCHOIX:\t\t");
    scanf("%d",&N_DATA);
    if(N_DATA==2)
    {
      MENU(head);
    }
    else if(N_DATA==1)
    {
      system("cls");
    }
  }
}


void close_changefct(data* head,pointer_p person)
{
  system("cls");
  int N_DATA=0;

  printf("\n############################################################################################\n");
  printf("#                                                                                          #\n");
  printf("#                                                                                          #\n");
  printf("#                          Vous avez terminer vos modifications  ?                         #\n");
  printf("#                                                                                          #\n");
  printf("#                   1)-OUI                                     2)-NON                      #\n");
  printf("#                                                                                          #\n");
  printf("#                                                                                          #\n");
  printf("############################################################################################\n");
  while(N_DATA!=1 && N_DATA!=2)
  {
    printf("\nCHOIX:\t\t");
    scanf("%d",&N_DATA);
    if(N_DATA==2)
    {
      change_data(head,person);
    }
    else if(N_DATA==1)
    {
      system("cls");
    }
  }
}

void verify(data* head)
{
  char password[20]="Ensias@2009";
  char attempt[20];
  printf("Veuillez reecrire le Mot de Passe :\t       ");
  scanf("%s",&attempt);

  if(strcmp(attempt,password)!=0)
  {
    MENU(head);
  }
}
