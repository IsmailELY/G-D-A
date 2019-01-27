#ifndef __STRUCT_H_
#define __STRUCT_H_

//a flag for sex, if the person is a man the flag will take the value 2 and if it's a woman it'll take the value 1
typedef enum  sex{f=1 ,m}sex;

//a struct countains data about a person
typedef struct drop_of_life
{
  char  NAME[20];
  char  Fst_NAME[20];
  char  ID[5];
  char  CIN[10];
  char  children_ID[20][5];
  int   N_child;
  sex   sex;
  int   birth[3];
  struct drop_of_life * spouse;
}person;

typedef person* pointer_p;


typedef struct linked_list
{
  pointer_p human;
  struct  linked_list * prev;
  struct  linked_list * next;
}data;

//branchement:
void login();
void MENU(data* head);
void close_menu(data* head);
void close_changefct(data* head,pointer_p person);
void verify(data* head);

//basic functions:

pointer_p create_enfant(data*head);   //it create a kid
data* reach_the_tail(data*head);                                      //it returns the last node in our linked list
int cmp_ID(pointer_p P1, pointer_p P2);
int cmp_NAME(pointer_p P1, pointer_p P2);                             //compare the char data
int cmp_FstNAME(pointer_p P1, pointer_p P2);
int cmp_CIN(pointer_p P1,pointer_p P2);
void swap_next(data*node);                                            //switch place with the next


//functions:
data* insert(data*head,pointer_p buddy);                 //it creates a new node that countain a new person
void delete(data*head,pointer_p buddy);         //it deletes a person from the linked list
void sort(data* head);                                   //it sorts our linked list by NAME and if two persons have the same NAME we'll compare their ID
void disp(data*head);                                    //display the linked list
pointer_p search_pers(data*head);                        //search a person
void change_data(data*head,pointer_p person);            //change someone's data
int age(pointer_p person);                               //calculate the exact age


//family functions:
void Disp_DATA_Children(data* head,pointer_p person);              //display children's data
char* Parent_of_kid(data* head,pointer_p person,int mode);         //return the Name of mode(1:mother |2:father) of a kid
void marry(pointer_p P1,pointer_p P2);                             //it marries two persons together
void divorce(pointer_p P1,pointer_p P2);                           // separate them

#endif
