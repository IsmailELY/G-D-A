#ifndef __STRUCT_H_
#define __STRUCT_H_

//a struct countains data about a person
typedef struct drop_of_life
{
  char  NAME[20];
  char  Fst_NAME[20];
  char  ID[10];
  char  CIN[10];
  struct drop_of_life  * DAD;
  struct drop_of_life  * MOM;
  int birth[3];
}person;

typedef person* pointer_p;


typedef struct linked_list
{
  pointer_p human;
  struct  linked_list * prev;
  struct  linked_list * next;
}data;

//basic functions:

void upper(pointer_p buddy);                 //it turns the data of a person to uppercase
pointer_p create_human(char NAME[20],char FST_NAME[20],char ID[10],char CIN[10],pointer_p DAD,pointer_p MOM,int day,int month,int year); //it create a new person
data* reach_the_tail(data*head);             //it return the last node in our linked list
int cmp_ID(pointer_p P1, pointer_p P2);
int cmp_NAME(pointer_p P1, pointer_p P2);
int cmp_FstNAME(pointer_p P1, pointer_p P2);
int cmp_CIN(pointer_p P1,pointer_p P2);
void swap_next(data*node1);                 //switch place with the next


//functions:
data* insert(data*head,pointer_p buddy);      //it create a new node that countain a new person
void delete(data*head,pointer_p buddy);       //it delete a person from the linked list
void sort(data* head);
void disp(data*head);
void Disp_Children(pointer_p DAD);


#endif
