#include "config.h"

int main(void)
{
    system("color 0f");
	list_t *list = NULL;
	u8 name[30]={0};
	u8 birth[30]={0};
	u8 identity[30]={0};
	u8 address[30]={0};
	u8 phone[30]={0};
	u8 classs[30]={0};
	u32 seat[30]={0};
	u32 choice = 0, num=0,req=0,nummm=0;
	list = CreateList();
	style();
	menu();
	do{
		printf("----------------------------------------------------------\n");
		printf("-------> Your Choice is: ");
		scanf("%d",&choice);
		switch(choice)
		{

     case 1:
				Display(list);
				break;

     case 2:

				printf("Client Name: ");
				fflush(stdin);
				gets(name);
				printf("Client Birth date (dd/mm/yyyy) : ");
				scanf("%d\n",&birth);
                fflush(stdin);
				printf("Passport ID (A********) : ");
				gets(identity);
				printf("Client Country: ");
                gets(address);
				printf("Client Phone Number: ");
				gets(phone);
				printf("Client Class (Business-Economy-Smoking): ");
                gets(classs);
				printf("Client Seat (A**) : ");
                gets(seat);
				if(client(list,name,birth,identity,address,phone,classs,seat) == RET_OK)
				{
					printf("Client has been added SUCCEFULLY\n");
				}
				else{
					printf("Error: Failed to Add New Client");
				}
				break;
     case 3:
				if(Delete(list)==RET_OK)
				{
					printf("The Client has been deleted successfully");
				}
				else
				{/* do nothing*/}
				break;

     case 4:
				if(ViewNclient(list,&num)== RET_OK)
				{
					printf("The number of available Clients: %d\n",num);
				}
				else{/*do nothing*/}
				break;

     case 5:
				if(Editclient(list,&req,&nummm)==RET_OK)
				{
					printf("The Client has been Modified succefully");
				}
				else
				{/* do nothing*/}
				break;

     case 6:
				printf("GOODBYE! Come Back SOON!");
				free(list);
				exit(0);

     case 7:    menu();

    default:
				printf(" ");
					}

}
while(1);
}
