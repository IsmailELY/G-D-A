#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"
#include <time.h>
#include <unistd.h>


int main()
{
  FILE * pointer = fopen("data_base","wb");
  pointer_p data=(pointer_p)malloc(sizeof(person));
  fseek(pointer,0,SEEK_SET);
  while(fgetc(pointer)!=EOF)
  {
    fseek(pointer,-1L,SEEK_CUR);
    fread(data,sizeof(person),1,pointer);
    printf("\n%s   %s",data->NAME,data->Fst_NAME);
  }
  fclose(pointer);
  free(data);
  return 0;
}
