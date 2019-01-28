#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"
#include <time.h>
#include <unistd.h>

// We're going to manage the children now :
void Disp_DATA_Children(data* head,pointer_p person)
{
  system("cls");
  char Sexe,Quitter;
  int j=0;
  if(person->N_child!=0)
  {
    for(data* i=head->next; i!=NULL;i= i->next)
    {
      for(int k=0;k<(person->N_child);k++)
      {
        if (i->human->ID==person->children_ID[k])
        {
          j++;
          if(i->human->sexe==f)
            Sexe='f';
          else
            Sexe='m';
          printf("\nKid No %d\n\tNAME:             %s\n\tFirst Name:  %s\n\tSexe:           %c\n\tID:             %d\n\tCIN:       %s\n\tKids:             %d\n",j,i->human->NAME,i->human->Fst_NAME,Sexe,i->human->ID,i->human->CIN,i->human->N_child);

        }
      }
    }
  }
  printf("\n\n                                        Q) Quitter\n\n");
  while(Quitter!='Q' && Quitter!='q')
  {
    scanf("%c",&Quitter);
  }
  system("cls");
}



//return the parent of a kid
char* Parent_of_kid(data* head,pointer_p person,int mode)   //mode=1: mother | mode=2 Father
{
  // initializing
  int flag=0;
  char* NAME=(char*)malloc(50);

  // going through the list and search the parent
  for(data*i=head->next;i!=NULL;i=i->next)
  {
    if((mode==1 && i->human->sexe==f)||(mode==2 && i->human->sexe==m)) //comparing the current id to the parent's child_id
    {
      for(int j=0;j<(i->human->N_child);j++)
      {
        if(person->ID==i->human->children_ID[j])
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
