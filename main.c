#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"


int main(void)
{
  data* head=(data*)malloc(sizeof(data));
  head->next=NULL;

  pointer_p abir=create_human("elmokhtari","abir","000000000","ad123456",NULL,NULL);
  data* p=insert(head,abir);

  printf("\nlet's test if create_human works:\nabir %s\n",abir->NAME);
  printf("\nlet's test if insert(from the node created) works:\nabir %s\n",p->human->NAME);
  printf("\nlet's test if insert(from the head) works:\nabir %s\n",head->next->human->NAME);

  pointer_p ismail=create_human("elyousfi","ismail","000000001","ad654321",NULL,NULL);
  p=insert(head,ismail);

  printf("\nwell ismail %s is successfully added\n",head->next->next->human->NAME);
  delete(head,ismail);
  if(head->next->next==NULL && strcmp(head->next->human->NAME,abir->NAME)==0)
    printf("\nwe managed to delete ismail from the linked list\n");

  return 0;
}
