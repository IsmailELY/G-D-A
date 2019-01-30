#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"
#include <time.h>
#include <unistd.h>



void MENU(data* head)
{
  data* NODE;
  pointer_p SBD;
  char *BIG_DATA=(char*)malloc(sizeof(50));
  int choice=10,N_DATA=0,N_DATA2=0;
  while (choice!=0)
  {
    system("cls");
    printf("\n#####################  Projet C Gestion des actes   ######################\n");
    printf("#                                                                        #\n");
    printf("#                                 MENU:                                  #\n");
    printf("#                                                                        #\n");
    printf("#                                                                        #\n");
    printf("#            1)            Ajouter une personne .                        #\n");
    printf("#                                                                        #\n");
    printf("#            2)           Supprimer une personne.                        #\n");
    printf("#                                                                        #\n");
    printf("#            3)  Modifier les enregistrements d une personne.            #\n");
    printf("#                                                                        #\n");
    printf("#            4)        Consulter la liste des personnes.                 #\n");
    printf("#                                                                        #\n");
    printf("#            5) Retourner le nom de mere ou pere d une personne.         #\n");
    printf("#                                                                        #\n");
    printf("#            6)         Retourner l age d une personne.                  #\n");
    printf("#                                                                        #\n");
    printf("#            7)          Trier la liste des personnes.                   #\n");
    printf("#                                                                        #\n");
    printf("#            8)            Imprimer donnees (Actes).                     #\n");
    printf("#                                                                        #\n");
    printf("#            9)       Afficher les enfants d'une personne                #\n");
    printf("#                                                                        #\n");
    printf("#            0)                    Quitter.                              #\n");
    printf("#                                                                        #\n");
    printf("#                                                                        #\n");
    printf("##########################################################################\n");
    printf("\nCHOIX:\t\t");
    scanf ("%d",&choice);

    switch(choice)
    {
      case 1:
        SBD=create_enfant(head);
        insert(head,SBD);
        break;



      case 2:     //DELETE A PERSON
        system("cls");
        SBD=search_pers(head);
        if(SBD!=NULL && SBD->ID!=0)
        {
          system("cls");                        //security
          printf("\n############################################################################################\n");
          printf("#                                                                                          #\n");
          printf("#                                                                                          #\n");
          printf("#                   Etes-vous sur de vouloir supprimer cette personne ?                    #\n");
          printf("#                                                                                          #\n");
          printf("#                   1)-OUI                                     2)-NON                      #\n");
          printf("#                                                                                          #\n");
          printf("#                                                                                          #\n");
          printf("############################################################################################\n");
          while(N_DATA2!=1 && N_DATA2!=2)
          {
            printf("\nCHOIX:\t\t");
            scanf("%d",&N_DATA2);
          }

          if(N_DATA2==1)
          {
            verify(head);
            delete(head,SBD);
          }
        }

        break;


      case 3:         //MODIFY DATA:
        system("cls");
        SBD=search_pers(head);
        if(SBD!=NULL && SBD->ID!=0)
          change_data(head,SBD);
        break;


      case 4:   //Show all the registred person
        system("cls");
        disp(head);
        break;

      case 5: // display the name of parent
        printf("\n\n________________________________________L'enfant :_______________________________________\n");
        sleep(2);
        SBD=search_pers(head);
        if(SBD!=NULL && SBD->ID!=0)
        {
          N_DATA=0;
          printf("\n############################################################################################\n");
          printf("#                                                                                          #\n");
          printf("#                                         CHOIX  :                                         #\n");
          printf("#                                                                                          #\n");
          printf("#                   1)-Mere                                    2)-Pere                     #\n");
          printf("#                                                                                          #\n");
          printf("#                                                                                          #\n");
          printf("############################################################################################\n");
          printf("\n ---->        ");
          while(N_DATA!=1 && N_DATA!=2)
          {
            scanf("%d",&N_DATA);
          }
          strcpy(BIG_DATA,Parent_of_kid(head,SBD,N_DATA));
          printf("\n\n                                %s\n",BIG_DATA);
          sleep(5);
        }
        break;

      case 6: //show the exact age of a person
        SBD=search_pers(head);
        if(SBD!=NULL && SBD->ID!=0)
        {
          system("cls");
          printf("\n\n\n                                L'age de   %s   %s   est :\n\n                                  --->      %d",SBD->NAME,SBD->Fst_NAME,age(SBD));
          sleep(5);
        }
        break;

      case 7:   //display the list
        system("cls");
        sort(head);
        printf("\n\n                                Maintenant votre liste est triee  !\n");
        sleep(3);
        break;

      case 8:
        system("cls");

        NODE=(data*)malloc(sizeof(data));
        do
        {
          NODE->human=search_pers(head);
        }
        while(NODE->human==NULL);

        if(NODE->human->ID!=0)
        {
          acte_generator(NODE,head);
        }
        break;

      case 9:
        system("cls");
        SBD=search_pers(head);
        if(SBD!=NULL && SBD->ID!=0)
          Disp_DATA_Children(head,SBD);

        break;

      case 0:
        system("cls");
        close_menu(head);
        break;

      default:
        printf("\n\nERREUR !!\t\t");
        break;
      }
    }
}
