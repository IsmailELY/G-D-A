#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"
#include <time.h>
#include <unistd.h>


//read all the data_base
void read_data(data*head)
{
  FILE* reader=fopen("data_base","rb");
  fseek(reader,0,SEEK_SET);
  pointer_p data=(pointer_p)malloc(sizeof(person));

  while(fread(data,sizeof(person),1,reader)!=0)
  {
    insert(head,data);
  }
  fclose(reader);
  free(data);
}



// save data of a person in our data_base
void save_data(data* head)
{
  FILE* write=fopen("data_base","wb");
  data* p=head->next;

  while(p!=NULL)
  {
    fwrite(p->human,sizeof(person),1,write);
    p=p->next;
  }
  fclose(write);
}
