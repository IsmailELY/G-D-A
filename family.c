#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"
#include <time.h>
#include <unistd.h>

// We're going to manage the children now :
void Disp_DATA_Children(data* head,pointer_p person)
{
  char Sex;
  int j=0;
  if(person->N_child!=0)
  {
    for(data* i=head->next; i!=NULL; i->next)
    {
      for(int k=0;k<(person->N_child);k++)
      {
        if (strcmp(i->human->ID,person->children_ID[k])==0)
        {
          j++;
          if(i->human->sex==f)
            Sex='f';
          else
            Sex='m';
          printf("\nKid No %d\n\tNAME:  %s\n\tFirst Name:  %s\n\tSex:  %c\n\tID:  %s\n\tCIN:  %s\n\tKids:  %d\n",j,i->human->NAME,i->human->Fst_NAME,Sex,i->human->ID,i->human->CIN,i->human->N_child);
        }
      }
    }
  }
}



//return the parent of a kid
char* Parent_of_kid(data* head,pointer_p person,int mode)   //mode=1: mother | mode=2 Father
{
  // initializing
  int flag=0;
  char* NAME=(char*)malloc(45);

  // going through the list and search the parent
  for(data*i=head->next;i!=NULL;i=i->next)
  {
    if((mode==1 && i->human->sex==f)||(mode==2 && i->human->sex==m)) //comparing the current id to the parent's child_id
    {
      for(int j=0;j<i->human->N_child;j++)
      {
        if(strcmp(person->ID,i->human->children_ID[j])==0)
        {
          flag=1;
          strcpy(NAME,i->human->NAME);
          strcat(NAME,"  ");
          strcat(NAME,i->human->Fst_NAME);
          break;
        }
      }
      if(flag==1)
        break;
    }
  }

  return NAME;
}


//divorce =(
void divorce(pointer_p P1,pointer_p P2)
{
  P1->spouse=NULL;
  P2->spouse=NULL;
}

//happy wedding =)
void marry(pointer_p P1,pointer_p P2)
{
  P1->spouse=P2;
  P2->spouse=P1;
}