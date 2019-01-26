#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structure.h"


int main(void)
{
  data* head=(data*)malloc(sizeof(data));
  head->next=NULL;
  head->prev=NULL;

  pointer_p abir=create_human("elmokhtari","abir","000000000","ad123456",NULL,NULL,6,9,1998);
  insert(head,abir);

  pointer_p ismail=create_human("elyousfi","ismail","000000001","ad654321",NULL,NULL,7,2,1999);
  insert(head,ismail);
  printf("\nwe added ismail");
  disp(head);

  delete(head,abir);
  printf("\nwe deleted abir");
  disp(head);

  insert(head,abir);
  printf("\nwe added abir again");
  disp(head);

  swap_next(head->next);
  printf("\nwe switched ismail and abir");
  disp(head);

  printf("\n we'll add dalia and saad and salah to the list:");
  pointer_p dalia=create_human("elaiche","dalia","000000002","ad000000",NULL,NULL,20,1,1998);
  insert(head,dalia);

  pointer_p saad=create_human("eljebbari","saad","000000003","ad546542",NULL,NULL,24,1,1999);
  insert(head,saad);

  pointer_p salah=create_human("elbeghdadi","salaheddine","000000004","ad951753",NULL,NULL,17,4,1998);
  insert(head,salah);
  disp(head);



  printf("OUR SORTED LIST:\n\n");
  sort(head);
  //the result we're expecting :    dalia elaich ->  elbeghdadi salah  ->  eljebbari saad  ->  elmokhtari  abir  ->  elyousfi  ismail
  //disp(head);

  return 0;
}
