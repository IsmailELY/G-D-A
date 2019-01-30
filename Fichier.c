#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"
#include <time.h>
#include <unistd.h>


//read all the data_base
void read_data(data*head)
{
  FILE* reader=fopen("data_base","rb");                  //lecture du fichier en mode binaire
  fseek(reader,0,SEEK_SET);                              //Ramène le pointeur vers 0
  pointer_p data=(pointer_p)malloc(sizeof(person));

  while(fread(data,sizeof(person),1,reader)!=0)
  {
    insert(head,data);                                 //On va insérer le contenu de personne vers la fin de la liste chaînée
    data=(pointer_p)malloc(sizeof(person));
  }
  fclose(reader);
}



// save all data in our data_base.bin
void save_data(data* head)
{
  FILE* write=fopen("data_base","wb");    //on a choisis le mode "w" pour écraser les données qui précèdent et la remplir avec nos nouvelles modifications.
  data* p=head->next;

  while(p!=NULL)                          //condition d'arrêt : on a atteint la fin de notre liste chainée
  {
    fwrite(p->human,sizeof(person),1,write);        //copie les données de la personne p->human à la fin du fichier
    p=p->next;
  }
  fclose(write);
}
