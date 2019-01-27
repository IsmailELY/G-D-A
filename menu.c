#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"
#include <time.h>
#include <unistd.h>



void MENU(data* head)
{
  data* NODE;
  pointer_p NOBODY,NOBODY2;
  char DATA_1[20],DATA_2[20],*BIG_DATA=(char*)malloc(sizeof(50));
  int choice=10,N_DATA,N_DATA2;
  while (choice!=0)
  {
    system("cls");
    printf("\n#######################    Bienvenue blbalblabla   #######################\n");
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
    printf("#            8)              Marier deux personne.                       #\n");
    printf("#                                                                        #\n");
    printf("#            9)             Separer deux personne.                       #\n");
    printf("#                                                                        #\n");
    printf("#            10)           Imprimer donnees (Actes).                     #\n");
    printf("#                                                                        #\n");
    printf("#            0)                    Quitter.                              #\n");
    printf("#                                                                        #\n");
    printf("#                                                                        #\n");
    printf("##########################################################################\n");
    printf("\nCHOIX:\t\t");
    scanf ("%d",&choice);

    switch(choice)
    {
      memset(DATA_1,0,20);
      memset(DATA_2,0,20);
      case 1:
        NOBODY=create_enfant(head);
        insert(head,NOBODY);
        break;



      case 2:     //DELETE A PERSON
        system("cls");
        NOBODY=search_pers(head);

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

        }
        delete(head,NOBODY);
        break;


      case 3:         //MODIFY DATA:
        NOBODY=search_pers(head);
        if(NOBODY!=NULL)
          change_data(head,NOBODY);
        break;


      case 4:   //Show all the registred person
        system("cls");
        disp(head);
        break;

      case 5: // display the name of parent
        printf("\n\n_________________________________________Le fils :________________________________________\n");
        NOBODY=search_pers(head);
        printf("\n############################################################################################\n");
        printf("#                                                                                          #\n");
        printf("#                                         CHOIX  :                                         #\n");
        printf("#                                                                                          #\n");
        printf("#                   1)-Mere                                    2)-Pere                     #\n");
        printf("#                                                                                          #\n");
        printf("#                                                                                          #\n");
        printf("############################################################################################\n");
        printf("\n ---->        ");
        scanf("%d",&N_DATA);
        strcpy(BIG_DATA,Parent_of_kid(head,NOBODY,N_DATA));
        printf("\n\n                                %s\n",BIG_DATA);
        sleep(5);
        break;

      case 6: //show the exact age of a person
        NOBODY=search_pers(head);
        system("cls");
        printf("\n\n\n                                L'age de   %s   %s   est :\n\n                                  --->      %d",NOBODY->NAME,NOBODY->Fst_NAME,age(NOBODY));
        sleep(5);
        break;

      case 7:   //display the list
        system("cls");
        sort(head);
        printf("\n\n                                Maintenant votre liste est triee  !\n")
        sleep(3);
        break;

      case 8:// marry two person
        printf("\n\n________________________________________ MARIER :________________________________________\n");
        printf("\n                          Veuillez préciser les deux personne  ");
        sleep(2);
        NOBODY=search_pers(head);
        NOBODY2=search_pers(head);
        marry(NOBODY,NOBODY2);
        system("cls");
        printf("\n\n                      %s   %s    Et   %s   %s   sont maintenant mariee !! ",NOBODY->NAME,NOBODY->Fst_NAME,NOBODY2->NAME,NOBODY2->Fst_NAME);
        sleep(4);
        break;

      case 9:
        printf("\n\n________________________________________ DIVORCE :________________________________________\n");
        printf("\n                          Veuillez préciser les deux personne  ");
        sleep(2);
        NOBODY=search_pers(head);
        NOBODY2=search_pers(head);
        divorce(NOBODY,NOBODY2);
        system("cls");
        printf("\n\n                        %s   %s    Et   %s   %s   ont divorce !! ",NOBODY->NAME,NOBODY->Fst_NAME,NOBODY2->NAME,NOBODY2->Fst_NAME);
        sleep(4);
        break;

      case 10


      case 0:

        close_menu(head);
        break;

      }
    }
}
