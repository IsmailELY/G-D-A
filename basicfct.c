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
  data* tail;

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
  sexe sexe;
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
      p->sexe=f;
    else if(number==2)
      p->sexe=m;
  }

  //we have to give him an ID
  tail=reach_the_tail(head);
  if(tail->prev==NULL)
    p->ID=1;
  else
    p->ID=(tail->human->ID)+1;


  //he's a kid so he doesn't have children yet
  p->N_child=0;

  //now we have to add those information to his parent's DATA
  switch(N_DATA)
  {
    case 1:
      printf("\n\n_________________________________________Le pere :________________________________________\n");
      sleep(2);

      do
      {DAD=search_pers(head);}while(DAD==NULL && DAD->ID==0);

      MUM->ID=0;
      system("cls");
      break;


    case 2:
      printf("\n\n_________________________________________La mere :________________________________________\n");
      sleep(2);
      do
        {MUM=search_pers(head);}while(MUM==NULL && MUM->ID==0);
      DAD->ID=0;
      system("cls");
      break;

    case 3:
      system("cls");
      printf("\n\n_________________________________________Le pere :________________________________________\n");
      sleep(2);
      do
      {DAD=search_pers(head);}while(DAD==NULL && DAD->ID==0);
      system("cls");
      printf("\n\n_________________________________________La mere :________________________________________\n");
      sleep(2);
      do
      {MUM=search_pers(head);}while(MUM==NULL && MUM->ID==0);

      system("cls");
      break;

    case 4:
      DAD->ID=0;
      MUM->ID=0;
      break;
  }

    if (DAD->ID!=0)
    {
      DAD->children_ID[DAD->N_child]=p->ID;
      DAD->N_child++;
    }
                                                    //if Parent's ID =0 that means the kid don't have a parent
    if (MUM->ID!=0)
    {
      MUM->children_ID[MUM->N_child]=p->ID;
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
   if((P1->ID)>(P2->ID))
    x=1;
  else if ((P1->ID)<(P2->ID))
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
