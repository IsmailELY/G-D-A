#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"

//a function that transform the important data of a person to uppercase
void upper(pointer_p buddy)
{
  strupr(buddy->NAME);
  strupr(buddy->ID);
  strupr(buddy->CIN);
  strupr(buddy->Fst_NAME);
}

data* reach_the_tail(data*head)
{
  data* tail=head;
  while(tail->next!=NULL)
  {
    tail=tail->next;
  }
  return tail;
}

pointer_p create_human(char NAME[20],char FST_NAME[20],char ID[10],char CIN[10],pointer_p DAD,pointer_p MUM,int day,int month,int year)
{
  pointer_p p=(pointer_p)malloc(sizeof(person));

  strcpy(p->NAME,NAME);
  strcpy(p->Fst_NAME,FST_NAME);
  strcpy(p->ID,ID);
  strcpy(p->CIN,CIN);
  p->DAD=DAD;                 //in case the mom or dad aren't identified
  p->MUM=MUM;                 //the user should write NULL as parameter
  p->birth[0]=day;
  p->birth[1]=month;
  p->birth[2]=year;

  upper(p);   //to make sure that all characters are uppercase

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
