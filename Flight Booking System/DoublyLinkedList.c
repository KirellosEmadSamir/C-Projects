/***********************************************************************/
/* File Name: DoublyLinkedList.h                                       */
/* File Info: This file has the implementation of the Doubly liked lists*/
/*             of Flight Booking System.                               */
/* Version  : V1.0                                                     */
/* Date     : 26 March 2022.                                           */
/* Author   : Kirellos Emad Samir                                      */
/***********************************************************************/


#include "DoublyLinkedList.h"
#include <string.h>

/****************************************************************/
/* Function Name: style()                                       */
/* Function Info: this function is used for Welcome Screen      */
/* Function Input: None.										*/
/* Function Return: None.                                       */
/****************************************************************/

void style(void){
    printf("\t\t\t\t\t\t   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t************************************************************************");
    printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO Flight Booking System  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
	//printf("\t\t\t-------------------- WELCOME TO Flight Booking System ------------------\n");
    printf("\t\t\t\t*********************************************************");
    printf("\n\n\t\t\t\t\t  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  NTI C Project  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
 //   printf("\t\t\t         -----------------  NTI C Project ----------------- \n\n");
    printf("\t\t\t\t\t***************************************\n");
    printf("\t\t\t\t            Coded By: Kirellos Emad Samir ");
    printf("\n\n\t\t\t\t\t\t   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
	printf(" Main Menu:\n");
	printf("----------------------------------------------------------\n");

	}
/****************************************************************/
/* Function Name: menu()                                        */
/* Function Info: this function creates main menu               */
/* Function Input: None.										*/
/* Function Return: None.                                       */
/****************************************************************/

void menu(void)
{
    printf(" View all Clients          -->  Enter (1)\n");
	printf(" Add a new clent           -->  Enter (2)\n");
	printf(" Delete a client           -->  Enter (3)\n");
	printf(" Total Registered Clients  -->  Enter (4)\n");
	printf(" Edit   a client           -->  Enter (5)\n");
	printf(" Exit  App                 -->  Enter (6)\n");
	printf(" Back to main menu Press -------->  7   \n");
}

/****************************************************************/
/* Function Name: CreateList()                                  */
/* Function Info: this function is used to creat the list	    */
/* Function Input: None.										*/
/* Function Return: None.                                       */
/****************************************************************/

list_t *CreateList(void)
{
	list_t *List = (list_t *)malloc(sizeof(list_t));
	if(NULL == List)
	{
		printf("Error: malloc failed to create your list !!!\n");
		return NULL;
	}
	else{
		List->Size = 0;
		List->Head = NULL;
		List->Tail = NULL;
	}
	return List;
}

/****************************************************************/
/* Function Name: Display()                                     */
/* Function Info: this function is used to view the list        */
/*                elements				                        */
/* Function Input: List --> is a pointer that will hold the     */
/*                      address of the required list.           */
/* Function Reuturn: ListState_t--> Return is Empty or Not.     */
/****************************************************************/
Status_t Display(list_t *List)
{
	Status_t ReturnStatus = RET_OK;
	if(NULL == List)
	{
		printf("Error: you Passed a NULL !!!\n");
		ReturnStatus = RET_NOK;
	}
	else{
		if(0 == (List->Size))
		{
			printf("Sorry ! the list is empty !!!\n");
			ReturnStatus = RET_NOK;
		}
		else{
				u32 i=0;
				node_t* temp= List->Head;
				for(i=0;i<List->Size;i++)
				{
					printf("Client No. :%d\n",i+1);
					printf("Client Name: %s\n",temp->name);
					printf("Client Class: %s\n",temp->classs);
					printf("Client Seat: %s\n",temp->seat);
					printf("--------------------------------\n");
					temp= temp->Next;
				}
		}
		return ReturnStatus;
	}
}

/****************************************************************/
/* Function Name: Addclient()                                   */
/* Function Info: this function is used to Add new client into  */
/*                the list.                                     */
/* Function Input: List --> is a pointer that will hold the     */
/*                           address of the required list.      */
/*               name --> is a pointer that hold the address    */
/*				          of an element of struct               */
/*               classs --> is a pointer that hold the address  */
/*				            of an element of struct             */
/*               seat --> is the variable that will hold the    */
/*                           the price data.                    */
/* Function Reuturn: None.                                      */
/****************************************************************/
Status_t client(list_t *List, u8 *name, u8 *birth, u8 *identity, u8 *address, u8 *phone, u8 *classs, u32 seat)
{
    Status_t ReturnStatus = RET_OK;
	if(NULL == List)
	{
		printf("Error: you Passed a NULL !!!\n");
		ReturnStatus = RET_NOK;
	}
	else{
		node_t *NodePtr = (node_t *)malloc(sizeof(node_t));
		if(NULL == NodePtr)
		{
			printf("Error: malloc failed to create your list !!!\n");
			ReturnStatus = RET_NOK;
		}
		else{
			if(List_Empty(List) ==  LIST_EMPTY)
			{
				List->Head = NodePtr;
				List->Tail = NodePtr;
				NodePtr->Previous = NULL;
			}
			else{
				NodePtr->Previous = List->Tail;
				List->Tail->Next = NodePtr;
				List->Tail = NodePtr;
			}
            strcpy(NodePtr->name, name);
			strcpy(NodePtr->birth, birth);
			strcpy(NodePtr->identity, identity);
			strcpy(NodePtr->address, address);
            strcpy(NodePtr->phone, phone);
			strcpy(NodePtr->classs, classs);
			strcpy(NodePtr->seat, seat);
			NodePtr->Next=NULL;
			List->Size++;
		}
	}	return ReturnStatus;
}
/****************************************************************/
/* Function Name: List_Empty()                                  */
/* Function Info: this function is used to check if the list    */
/*                is empty or not.                      	    */
/* Function Input: List --> is a pointer that will hold the     */
/*                      address of the required list.           */
/* Function Reuturn: ListState_t--> Return is Empty or Not.     */
/****************************************************************/
static ListState_t List_Empty(list_t *List)
{
    if(NULL == List)
	{
		printf("Error: you Passed a NULL !!!\n");
	}
	else{
		ListState_t ReturnState = LIST_NEMPTY;
		if(0 == (List->Size))
		{
			ReturnState = LIST_EMPTY;
		}
		else{/* Do Nothing*/ }
		return ReturnState;
	}
}

/****************************************************************/
/* Function Name: Delete()                                      */
/* Function Info: this function is used to remove elements from */
/*                the list.                                     */
/* Function Input: List --> is a pointer that will hold the     */
/*                      address of the required list.           */
/* Function Reuturn: ListState_t--> Return is Empty or Not.     */
/****************************************************************/
Status_t Delete(list_t *List)
{
    Status_t ReturnStatus = RET_NOK;
	node_t *BufferPtr = NULL;
	if(NULL == List)
	{
		printf("Error: you Passed a NULL !!!\n");
	}
	else{
		if(List_Empty(List) == LIST_EMPTY)
		{
			printf("Sorry,There's no Clients to DELETE !!!!\n");
		}
		else{
			BufferPtr = List->Head;
			s32 index;
			printf("please enter Client Number you want to delete from (1 : %d): ",List->Size);
			scanf("%d", &index);
			if (index > List->Size || index<=0)
			{
				printf("Error! you entered a wrong number. Try again");
				fflush(stdin);
				scanf("%d", index);
			}
			else if(1 == (List->Size))
			{
				List->Head = NULL;
				List->Tail = NULL;
			}
			else if (index == 1)//first
			{
				List->Head = List->Head->Next;
				List->Head->Previous = NULL;
			}
			else if(index == (List->Size))//last
			{
				BufferPtr=List->Tail;
				List->Tail= List->Tail->Previous;
				List->Tail->Next= NULL;
			}
			else{
				u32 i =0;
				for(i=0; i<index-1; i++)
				{
					BufferPtr=BufferPtr->Next;
				}
				BufferPtr->Previous->Next = BufferPtr->Next;
				BufferPtr->Next->Previous= BufferPtr-> Previous;
			}
			free(BufferPtr);
			List->Size--;
			ReturnStatus = RET_OK;
		}
		return ReturnStatus;
	}
}

/****************************************************************/
/* Function Name: ViewClient()                                  */
/* Function Info: this function is used to view the number of   */
/*                elements existed in the list.                 */
/* Function Input: List --> is a pointer that will hold the     */
/*                      address of the required list.           */
/*                 num --> is a pointer to variable that will   */
/*                          hold the size of the list.          */
/* Function Reuturn: None.                                      */
/****************************************************************/
Status_t ViewNclient(list_t *List, u32 *num)
{
    Status_t ReturnStatus = RET_OK;
	if(NULL == List)
	{
		printf("Error: you Passed a NULL !!!\n");
		ReturnStatus = RET_NOK;
	}
	else{
		if(List_Empty(List) == LIST_EMPTY)
		{
			printf("Booking System is Empty!!!!\n");
			ReturnStatus = RET_NOK;
		}
		else{
			*num = List->Size;
		}
	}
	return ReturnStatus;
}

/****************************************************************/
/* Function Name: EditClient()                                  */
/* Function Info: this function is used to Edit the Info.  of   */
/*                  Client existed in the list.                 */
/* Function Input: List --> is a pointer that will hold the     */
/*                      address of the required list.           */
/*                 req --> is a pointer to variable that will   */
/*                          hold the size of the list.          */
/* Function Reuturn: None.                                      */
/****************************************************************/
Status_t Editclient(list_t *List, u32 *req,u32 *nummm)
{
    Status_t ReturnStatus = RET_NOK;
	node_t *Buffer = NULL;
	if(NULL == List)
	{
		printf("Error: you Passed a NULL !!!\n");
	}
	else{
		if(List_Empty(List) == LIST_EMPTY)
		{
			printf("Sorry,There's no Clients to Edit !!!!\n");
		}
		else{
			Buffer = List->Head;
			s32 index;
			printf("please enter Client Number you want to Edit from (1 : %d): ",List->Size);
			scanf("%d", &index);
			if (index > List->Size || index<=0)
			{
				printf("Error! you entered a wrong number. Try again");
				fflush(stdin);
				scanf("%d", index);
			}
		else{
                    u32 i=0;
                    node_t* Buffer= List->Head;
                    for(i=0;(i<List->Size)&&(nummm);i++){
                    printf("Edit Name      -->(1) \n");
					printf("Edit Class     -->(2) \n");
					printf("Edit Seat      -->(3) \n");
					printf("Exit Edit Menu -->(0) \n");
					printf("--------------------------------\n");
                    printf("Enter Your Choice :\n");
                    scanf("%d",&nummm);
					printf("--------------------------------\n");
					if(nummm == 1)
                    {
                        fflush(stdin);
                        printf("New Name:");
                        gets(Buffer->name);
                    }
                    else if(nummm == 2)
                    {
                       fflush(stdin);
                        printf("New Class:");
                        gets(Buffer->classs);
                    }
                    else if(nummm == 3)
                    {
                        fflush(stdin);
                        printf("New Seat:");
                        gets(Buffer->seat);
                    }
            }
		}
	}	return ReturnStatus;
}
}

