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
  /*delete(head,ismail);
  if(head->next->next==NULL && strcmp(head->next->human->NAME,abir->NAME)==0)
    printf("\nwe managed to delete ismail from the linked list\n");
*/
    printf("The comparison functions : ");
    printf("\n");
    printf("Let's compare the Ids : %d", cmp_ID(abir,abir));
    printf("\n");
    printf(" Let's compare the Names (Last names) : %d",cmp_NAME(abir,ismail));
    printf("\n");
    printf("Let's compare the First Names : %d",cmp_FstNAME(abir,ismail));
    printf("\n");
    printf("Let's compare the CIN numbers : %d " ,cmp_CIN(abir,ismail));

  return 0;
}
