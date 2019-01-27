#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"
#include <time.h>
#include <unistd.h>

data* reach_the_tail(data*head)
{
  data* tail=head;
  while(tail->next!=NULL)
  {
    tail=tail->next;
  }
  return tail;
}

pointer_p create_enfant(data*head)
{
  int N_DATA;
  system("cls");
  printf("\n############################################################################################\n");
  printf("#                                                                                          #\n");
  printf("#                                                                                          #\n");
  printf("#                                 A-il des parents ou pas  ?                               #\n");
  printf("#                                                                                          #\n");
  printf("#                     1)-PERE                                   2)-MERE                    #\n");
  printf("#                                                                                          #\n");
  printf("#                                                                                          #\n");
  printf("#                     3)-Les Deux                               4)-Aucun                   #\n");
  printf("#                                                                                          #\n");
  printf("#                                                                                          #\n");
  printf("############################################################################################\n");
  while(N_DATA!=1 && N_DATA!=2 && N_DATA!=3 && N_DATA!=4)
  {  scanf("%d",&N_DATA); }
  system("cls");
  //initializing
  sex sex;
  char DATA[20];
  int number;
  pointer_p p=(pointer_p)malloc(sizeof(person)),DAD=(pointer_p)malloc(sizeof(person)),MUM=(pointer_p)malloc(sizeof(person));

  //NAME:
  printf("\nTappez le NOM :           ");
  scanf("%s",&DATA);
  strupr(DATA);
  strcpy(p->NAME,DATA);

  //Fst_NAME:
  printf("\nTappez le PRENOM :        ");
  scanf("%s",&DATA);
  strupr(DATA);
  strcpy(p->Fst_NAME,DATA);

  //ID:
  printf("\nTappez l ID(4 chiffre):   ");
  scanf("%s",&DATA);
  strupr(DATA);
  strcpy(p->ID,DATA);

  //CIN:
  printf("\nTappez le CIN :           ");
  scanf("%s",&DATA);
  strupr(DATA);
  strcpy(p->CIN,DATA);

  //birth:
  printf("\n\nLa date de naissance:\n\n\tJour:\t");
  scanf("%d",&p->birth[0]);

  printf("\tMois:\t");
  scanf("%d",&p->birth[1]);

  printf("\tAnnee:\t");
  scanf("%d",&p->birth[2]);

  //sexe:
  number=0;
  while(number!=1 && number!=2)
  {
    printf("\n\nSexe :\t1)-F\t2)-M\t\t --->\t");
    scanf("%d",&number);
    if(number==1)
      p->sex=f;
    else if(number==2)
      p->sex=m;
  }
  //he's a kid so he doesn't have children yet nor a spouse
  p->N_child=0;
  p->spouse=NULL;

  //now we have to add those information to his parent's DATA
  switch(N_DATA)
  {
    case 4:
      strcpy(DAD->ID,"");
      strcpy(MUM->ID,"");
      break;

    case 3:
      printf("\n\n_________________________________________Le pere :________________________________________\n");
      sleep(2);
      DAD=NULL;
      while(DAD==NULL)
        {DAD=search_pers(head);}
      system("cls");
      printf("\n\n_________________________________________La mere :________________________________________\n");
      sleep(2);
      MUM=NULL;
      while(MUM==NULL)
        {MUM=search_pers(head);}
      system("cls");
      break;

    case 2:
      printf("\n\n_________________________________________La mere :________________________________________\n");
      sleep(2);
      MUM=NULL;
      while(MUM==NULL)
        {MUM=search_pers(head);}
      strcpy(DAD->ID,"");
      system("cls");
      break;

    case 1:
      printf("\n\n_________________________________________Le pere :________________________________________\n");
      sleep(2);
      DAD==NULL;
      while(DAD==NULL)
        {DAD=search_pers(head);}
      strcpy(MUM->ID,"");
      system("cls");
      break;
  }
  if (strcmp(DAD->ID,"")!=0)
  {

    strcpy(DAD->children_ID[DAD->N_child],p->ID);
    DAD->N_child++;
  }
                                                    //if Parent's ID ="" that means the kid don't have a parent
  if (strcmp(MUM->ID,"")!=0)
  {

    strcpy(MUM->children_ID[MUM->N_child],p->ID);
    MUM->N_child++;
  }

  return p;
}


void swap_next(data*node)
{
  if(node->next!=NULL && node->prev!=NULL)
  {
    pointer_p stock=node->human;
    node->human=node->next->human;
    node->next->human=stock;
  }
}



int cmp_ID(pointer_p P1, pointer_p P2)
{
  int x=0;
   if(strcmp((P1->ID),(P2->ID))>0)
    x=1;
  else if (strcmp((P1->ID),(P2->ID))<0)
    x=-1;

 return x;
}

int cmp_NAME(pointer_p P1, pointer_p P2)
{
  int x=0;
   if(strcmp((P1->NAME),(P2->NAME))>0)
    x=1;

  else if (strcmp((P1->NAME),(P2->NAME))<0)
    x=-1;

  return x;
}


int cmp_FstNAME(pointer_p P1, pointer_p P2)
{
  int x=0;
   if(strcmp((P1->Fst_NAME),(P2->Fst_NAME))>0)
    x=1;
  else if (strcmp((P1->Fst_NAME),(P2->Fst_NAME))<0)
    x=-1;

  return x;
}

int cmp_CIN(pointer_p P1,pointer_p P2)
{
  int x=0;
  if(strcmp((P1->CIN),(P2->CIN))>0)
    x=1;
  else if (strcmp((P1->CIN),(P2->CIN))<0)
    x=-1;

  return x;
}
