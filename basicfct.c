#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"

//a function that transform the important data of a person to uppercase
void upper(pointer_p perso)
{
  strupr(perso->NAME);
  strupr(perso->ID);
  strupr(perso->CIN);
  strupr(perso->Fst_NAME);
}


pointer_p create_human(char NAME[20],char FST_NAME[20],char ID[10],char CIN[10],pointer_p DAD,pointer_p MOM)
{
  pointer_p p=(pointer_p)malloc(sizeof(person));

  strcpy(p->NAME,NAME);
  strcpy(p->Fst_NAME,FST_NAME);
  strcpy(p->ID,ID);
  strcpy(p->CIN,CIN);
  p->DAD=DAD;                 //in case the mom or dad aren't identified
  p->MOM=MOM;                 //the user should write NULL as parameter

  upper(p);   //to make sure that all characters are uppercase

  return p;
}





data* insert(data* head,pointer_p budy)
{
  data*p=(data*)malloc(sizeof(data));
  data* seeker=head;

  while(seeker->next!=NULL)   // we have to reach the last node in our linked list
    seeker=seeker->next;

  p->human=budy;
  p->next=NULL;               // we add our new pointer properly
  p->prev=seeker;

  seeker->next=p;             //we associate the last node to the new one

  return p;                   // the returning isn't necessarily important but it could be useful
}


void delete(data*head,pointer_p budy)
{
  data* seeker=head;
  int flag=0;
  char NAME[20],CIN[10];

  strcpy(NAME,budy->NAME);
  strcpy(CIN,budy->CIN);

  while(flag==0 && seeker!=NULL)
  {
    if(strcmp(NAME,seeker->human->NAME)==0 && strcmp(CIN,seeker->human->CIN)==0 )
      flag=1;
    else
      seeker=seeker->next;
  }

  if(flag==1 && seeker->next!=NULL)
  {
    seeker->prev->next=seeker->next;
    seeker->next->prev=seeker->prev;
    free(seeker);
  }
  else if(flag==1 && seeker->next==NULL)
  {
    seeker->prev->next=NULL;
    free(seeker);
  }
  else
    printf("\n%s %s doesn't exist\n",budy->NAME,budy->Fst_NAME);
}
