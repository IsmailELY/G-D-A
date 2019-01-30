#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"
#include <time.h>
#include <unistd.h>

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
  //initialising
  data* seeker=head->next;
  int flag=0;



  while(flag==0 && seeker!=NULL)
  {
    if(cmp_NAME(buddy,seeker->human)==0 && cmp_FstNAME(buddy,seeker->human)==0 && cmp_CIN(buddy,seeker->human)==0 && cmp_ID(buddy,seeker->human)==0 )
      flag=1;   //a mark that'll inform us if we found our buddy or not
    else
      seeker=seeker->next;
  }

  if(flag==1 && seeker->next!=NULL)       //we're inside the linked list
  {
    seeker->prev->next=seeker->next;      //make sure that the previous node isn't pointing on the node that countains buddy
    seeker->next->prev=seeker->prev;      //we're doing the same thing for the next node

    free(seeker);
  }
  else if(flag==1 && seeker->next==NULL)  //that means our buddy is stored at the last node of our linked list
  {
    seeker->prev->next=NULL;
    free(seeker);
  }
  else
    printf("\n\aCette personne n'existe pas\n");  //flag=0


}


void sort(data*head)
{
  for(data*i=head->next;i->next->next!=NULL;i=i->next)    //it's the bubble sort
  {
    for(data*j=head->next;j->next!=NULL;j=j->next)
    {
      if(cmp_NAME(j->human,j->next->human)==1)            //checking if person'name is bigger than the next one's name
      {
        swap_next(j);
      }
      else if((cmp_NAME(j->human,j->next->human)==0) && (cmp_ID(j->human,j->next->human)==1))
      {                                                   //it's our second criteria we're basing our sorting on
        swap_next(j);
      }
    }
  }
}


void disp(data*head)
{
  char Quitter='a';
  char sexe;

  printf("\n_______________________________La liste des personnes:______________________________\n");
  printf("|                                                                                    \n");
  for(data*i=head->next;i!=NULL;i=i->next)      //we're going through our linked list
  {
    if(i->human->sexe==f)
      sexe='f';
    else
      sexe='m';

    printf("|                                                                                    \n");
    printf("|               NOM et Prenom      :           %s   %s                                    \n",i->human->NAME,i->human->Fst_NAME);
    printf("|               ID                 :           %d                                         \n",i->human->ID);
    printf("|               CIN                :           %s                                         \n",i->human->CIN);
    printf("|               Sexe               :           %c                                         \n",sexe);
    printf("|               Nbre d'enfant      :           %d                                         \n",i->human->N_child);
    printf("|               Date de naissance  :        %d / %d / %d                                  \n",i->human->birth[0],i->human->birth[1],i->human->birth[2]);
  }
  printf("|                                                                                    \n");
  printf("|                                                                Q) Quitter      \n");
  printf("|                                                                                    \n");
  printf("|____________________________________________________________________________________\n");

  while(Quitter!='Q' && Quitter!='q')
  {
    scanf("%c",&Quitter);
  }

}



pointer_p search_pers(data*head)
{
  char DATA_1[20];
  int mode=0,N_DATA;
  pointer_p the_one=(pointer_p)malloc(sizeof(person));
  int flag=0;
  //initializing

  while(mode!=1 && mode!=2 && mode!=3 && mode!=4)
  {
    printf("\n\n_________Choisissez le type de Data que vous connaissiez sur cette personne:_________\n");
    printf("|                                                                                    |\n");
    printf("|                                                                                    |\n");
    printf("|                                 1) NOM et PRENOM                                   |\n");
    printf("|                                                                                    |\n");
    printf("|                                 2)     CIN                                         |\n");
    printf("|                                                                                    |\n");
    printf("|                                 3)     ID                                          |\n");
    printf("|                                                                                    |\n");
    printf("|                                 4)   Annuler                                       |\n");
    printf("|____________________________________________________________________________________|\n");
    printf("\n CHOIX:\t\t");
    scanf("%d",&mode);

    while(mode!=1 && mode!=2 && mode!=3 && mode!=4)
    {
      printf("\n");
      printf("\n\a                          Mode incorrect !\n");
      scanf("%d",&mode);
    }

    switch(mode)                  //this will helps us out to insert the appropriate data
    {
      case 1:

        printf("\nTapez le NOM :             ");
        scanf("%s",DATA_1);
        strcpy(the_one->NAME,DATA_1);
        strupr(the_one->NAME);

        printf("\nTapezle PRENOM :           ");
        scanf("%s",DATA_1);
        strcpy(the_one->Fst_NAME,DATA_1);
        strupr(the_one->Fst_NAME);
        break;

      case 2:

        printf("\nTapez le CIN:\t\t");
        scanf("%s",DATA_1);
        strcpy(the_one->CIN,DATA_1);
        strupr(the_one->CIN);
        break;

      case 3 :
        printf("\nTapez le ID:\t\t");
        scanf("%d",&N_DATA);
        the_one->ID=N_DATA;
        break;

      case 4 :
        the_one->ID=0;
        flag=1;
        break;
    }
  }

  system("cls");

  if(mode!=4)
  {
    for(data*i=head->next;i!=NULL;i=i->next)                                                       //We'll go throught our linked list and comparing the data
    {                                                                                              //of each person(node->human) and returning the first person
      if(mode==1 && cmp_NAME(i->human,the_one)==0 && cmp_FstNAME(i->human,the_one)==0)             //whose data is compatible
      {
        flag=1;
        the_one=i->human;
        break;
      }

      else if(mode==2 && cmp_CIN(i->human,the_one)==0)
      {
        flag=1;
        the_one=i->human;
        break;
      }

      else if(mode==3 && cmp_ID(i->human,the_one)==0)
      {
        flag=1;
        the_one=i->human;
        break;
      }
    }
  }


  if(flag==0)
  {
    printf("\n\aThis person doesn't exist !\n");      //if the flag equale 0 that means we didn't find the person
    sleep(2);
    the_one=NULL;
  }
  system("cls");
  return the_one;
}


int age(pointer_p person)
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);  //on obtient la date du jour grâce a cette fonction

  int age=tm.tm_year+1900 - person->birth[2];

  if(person->birth[1]>tm.tm_mon+1)
    age--;
  else if(person->birth[0]>tm.tm_mday)
    age--;

  return age;
}



void change_data(data* head,pointer_p person)
{
  char DATA[20];
  int i=0,N_DATA,N_DATA2;
  while(i!=8)
  {
    N_DATA=0;
    printf("\n\n_________________Choisis le type de Data que vous voulez modifier:__________________\n");
    printf("|                                                                                    |\n");
    printf("|                                                                                    |\n");
    printf("|                            1)         NOM                                          |\n");
    printf("|                                                                                    |\n");
    printf("|                            2)        PRENOM                                        |\n");
    printf("|                                                                                    |\n");
    printf("|                            3)          Id                                          |\n");
    printf("|                                                                                    |\n");                      //THE MENU
    printf("|                            4)          CIN                                         |\n");
    printf("|                                                                                    |\n");
    printf("|                            5)          Sexe                                        |\n");
    printf("|                                                                                    |\n");
    printf("|                            6)    Ajouter des enfants                               |\n");
    printf("|                                                                                    |\n");
    printf("|                            7)   Supprimer des enfants                              |\n");
    printf("|                                                                                    |\n");
    printf("|                            8)         Quitter                                      |\n");
    printf("|                                                                                    |\n");
    printf("|____________________________________________________________________________________|\n");
    printf("\n CHOIX:\t\t");
    scanf("%d",&i);

    system("cls");

    switch(i)
    {
      case 1:
        printf("\nTapez le nouveau NOM :\n");
        scanf("%s",DATA);
        strcpy(person->NAME,DATA);
        strupr(person->NAME);
        break;

      case 2:
        printf("\nTapez le nouveau PRENOM :\n");
        scanf("%s",DATA);
        strcpy(person->Fst_NAME,DATA);
        strupr(person->Fst_NAME);
        break;

      case 3:
        printf("\nTapez le nouveau ID:\n");
        scanf("%d",&N_DATA);
        person->ID=N_DATA;
        break;

      case 4:
        printf("\nTapez le nouveau CIN :\n");
        scanf("%s",DATA);
        memset(person->CIN,0,10);
        strcpy(person->CIN,DATA);
        strupr(person->CIN);
        break;

      case 5:
      printf("\n############################################################################################\n");
      printf("#                                                                                          #\n");
      printf("#                                                                                          #\n");
      printf("#                                     Choisir le sexe :                                    #\n");
      printf("#                                                                                          #\n");
      printf("#                       1)-Femme                             2)-Homme                      #\n");
      printf("#                                                                                          #\n");
      printf("#                                                                                          #\n");
      printf("############################################################################################\n");
        scanf("%d",&N_DATA);
        if(N_DATA==1)
          person->sexe=f;
        else if(N_DATA==2)
          person->sexe=m;
        else
          printf("\n\aErreur !\n");
        break;

      case 6:
        printf("Tapez le nombre d enfant que vous voulez ajouter :\t\t");     //fixing the number of children to Add
        scanf("%d",&N_DATA);
        for(int j=0;j<N_DATA && j<20-(person->N_child);j++) //on a deux conditions d'arrêt : la 1ere <nombre souhaité et la 2eme <nombre d'enfants permis (20)
        {
          printf("\nTapez l ID du nouvel enfant :\t");            //adding the child's ID
          scanf("%d",&N_DATA2);
          person->children_ID[person->N_child+j]=N_DATA2;
          person->N_child++;                           //updating the number of children
        }
        break;

      case 7:
        if(person->N_child!=0)
        {
          printf("\n_____________________________Voici les ID de ces enfants_____________________________\n");
          printf("|                                                                                    \n");
          for(int j=0;j<person->N_child;j++)
          {
            printf("|                            %d) %d                                           \n",j,person->children_ID[j]);  // a menu to choose the ID to remove
            printf("|                                                                                    \n");
          }
          printf("|____________________________________________________________________________________\n");

          printf("\n\n                 Tapez le nombre d enfant que vous voulez enlever:\t\t");
          scanf("%d",&N_DATA);

          for(int k=0;k<N_DATA;k++)
          {

            printf("\n    -Choisissez un ID :\t\t\t");
            scanf("%d",&N_DATA2);

            while(N_DATA2<person->N_child-2 && N_DATA2>-1)
            {
                    // delete process
              person->children_ID[N_DATA2]=person->children_ID[N_DATA2+1];
              N_DATA2++;
            }
            person->children_ID[N_DATA2]=0;         //we empty the last ID
            person->N_child--;                                //updating the number of children
          }
        break;

      case 8:
        close_changefct(head,person);
        break;                        //QUIT

      default:
        printf("\n\aError ! please tape the correct number .");
      }
    }
  }
}
