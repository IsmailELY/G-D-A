#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"


data* insert(data* head,pointer_p buddy)
{
  data*p=(data*)malloc(sizeof(data));
  data* seeker=reach_the_tail(head);

  p->human=buddy;
  p->next=NULL;               // we add our new pointer properly
  p->prev=seeker;

  seeker->next=p;             //we associate the last node to the new one

  return p;                   // the returning isn't necessarily important but it could be useful
}



void delete(data*head,pointer_p buddy)
{
  data* seeker=head->next;
  int flag=0;
  char NAME[20],CIN[10];

  strcpy(NAME,buddy->NAME);
  strcpy(CIN,buddy->CIN);

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
    printf("\n%s %s doesn't exist\n",buddy->NAME,buddy->Fst_NAME);
}


void sort(data*head)
{
  for(data*i=head->next;i->next->next!=NULL;i=i->next)
  {
    for(data*j=head->next;j->next!=NULL;j=j->next)
    {
      if(cmp_NAME(j->human,j->next->human)>0)
      {
        swap_next(j);
      }
      else if((cmp_NAME(j->human,j->next->human)==0) && (cmp_ID(j->human,j->next->human)>0))
      {
        swap_next(j);
      }
    }
  }
}


void disp(data*head)
{
  printf("\nThe Data List :\n\n");
  for(data*i=head->next;i!=NULL;i=i->next)
  {
    if(i->next==NULL)
      printf("%s  %s",i->human->NAME,i->human->Fst_NAME);
    else
      printf("%s  %s  ->",i->human->NAME,i->human->Fst_NAME);
  }
  printf("\n\n");
}

// We're going to manage the children now :

void Disp_Children(pointer_p DAD)
{
  for(data* i=head->next; i!=NULL; i->next)
  {
    if ((cmp_NAME(*i->*human->DAD.NAME, DAD.NAME))==1)
    {
      printf("%s", human->NAME);
    }
  }
}
