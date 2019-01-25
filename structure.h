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
}person;

typedef person* pointer_p;


typedef struct linked_list
{
  pointer_p human;
  struct  linked_list * prev;
  struct  linked_list * next;
}data;

//basic functions:

void upper(pointer_p perso);                 //it turns the data of a person to uppercase
pointer_p create_human(char NAME[20],char FST_NAME[20],char ID[10],char CIN[10],pointer_p DAD,pointer_p MOM);
                                             //it create a new person
data* insert(data*head,pointer_p budy);      //it create a new node that countain a new person
void delete(data*head,pointer_p budy);       //it delete a person from the linked list

#endif
