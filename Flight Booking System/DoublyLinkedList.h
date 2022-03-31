/***********************************************************************/
/* File Name: DoublyLinkedList.h                                       */
/* File Info: This file has the implementation of the liked lists of	   */
/*            Flight Booking System.                                   */
/* Version  : V1.0                                                     */
/* Date     : 26 March 2022.                                           */
/* Author   : Kirellos Emad Samir                                        */
/***********************************************************************/

#ifndef DOUBLYLINKEDLIST_H_INCLUDED
#define DOUBLYLINKEDLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"

#ifndef NULL
#define NULL ((void *)0)
#endif


typedef struct node{
	u8 name[30];
	u8 birth[30];
	u8 identity[30];
	u8 address[30];
	u8 phone[30];
    u8 classs[30];
	u8 seat[30];
	struct node *Next;
	struct node *Previous;
}node_t;

typedef struct List{
	u32 Size;
	node_t *Head;
	node_t *Tail;
}list_t;

typedef enum{
	LIST_EMPTY,
	LIST_NEMPTY
}ListState_t;

typedef enum{
	RET_NOK,
	RET_OK
}Status_t;

/****************************************************************/
/* Function Name: style()                                       */
/* Function Info: this function for Welcome Screen              */
/****************************************************************/
void style(void);

/****************************************************************/
/* Function Name: menu()                                        */
/* Function Info: this function creates main menu               */
/****************************************************************/
void menu(void);

/****************************************************************/
/* Function Name: CreateList()                                  */
/* Function Info: this function create the list                 */
/****************************************************************/
list_t *CreateList(void);

/****************************************************************/
/* Function Name: Display()                                     */
/* Function Info: –this function to view t clients information  */
/****************************************************************/
Status_t Display(list_t *List);

/****************************************************************/
/* Function Name: Addclient()                                   */
/* Function Info: this function is used to Add new client i     */
/*                the list.                                     */
/****************************************************************/
Status_t client(list_t *List, u8 *name, u8 *birth, u8 *identity, u8 *address, u8 *phone, u8 *classs, u32 seat);

/****************************************************************/
/* Function Name: List_Empty()                                  */
/* Function Info: this function is used to check if the list    */
/*                is empty or not.                      	    */
/****************************************************************/
static ListState_t List_Empty(list_t *List);

/****************************************************************/
/* Function Name: Delete()                                      */
/* Function Info: this function is used to remove elements from */
/*                the list.                                     */
/****************************************************************/
Status_t Delete(list_t *List);

/****************************************************************/
/* Function Name: ViewClient()                                  */
/* Function Info: this function is used to view the number of   */
/*                elements existed in the list.                 */
/****************************************************************/
Status_t ViewNclient(list_t *List, u32 *num);

/****************************************************************/
/* Function Name: ViewClient()                                  */
/* Function Info: this function is used to Edit the Info.  of   */
/*                  Client existed in the list.                 */
/****************************************************************/
Status_t Editclient(list_t *List, u32 *req,u32 *nummm);



#endif // DOUBLYLINKEDLIST_H_INCLUDED
