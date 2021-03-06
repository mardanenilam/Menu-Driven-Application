#include<stdio.h>
#include<stdlib.h>

struct node{
	int Data;
	struct node *Next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head, int no){
	PNODE newN=NULL;
	newN=(PNODE)malloc(sizeof(NODE));   //Typecasting with PNODE , allocating memory
	newN->Data=no;
	newN->Next=NULL;
	
	if(*Head==NULL){
		*Head=newN;
	}
	else{
		newN->Next=*Head;
		*Head=newN;
	}
}
void InsertLast(PPNODE Head, int no){
	PNODE newN=NULL;
	PNODE Temp=*Head;
	newN=(PNODE)malloc(sizeof(NODE));
	newN->Data=no;
	newN->Next=NULL;
	
	if(*Head==NULL){
		*Head=newN;
	}
	else{
		while(Temp->Next!=NULL){
			Temp=Temp->Next;
		}
		Temp->Next=newN;
	}
}
void Display(PNODE Head){
	while(Head!=NULL){
		printf("|%d|->",Head->Data);
		Head=Head->Next;
	}
	printf("NULL\n");
}
int Count(PNODE Head){
	int iCnt=0;
	while(Head!=NULL){
		iCnt++;
		Head=Head->Next;
	}
	return iCnt;
}
void DeleteFirst(PPNODE Head){
	PNODE Temp=*Head;
	if(*Head==NULL){
		return;
	}
	else if((*Head)->Next==NULL){
		free(*Head);
		*Head=NULL;
	}
	else{
		(*Head)=(*Head)->Next;
		free(Temp);
	}
}
void DeleteLast(PPNODE Head){
	PNODE Temp=*Head;
	if(*Head==NULL){
		return;
	}
	else if((*Head)->Next==NULL){
		free(*Head);
		*Head=NULL;
	}
	else{
		while(Temp->Next->Next!=NULL){   // travel till second last
		    Temp=Temp->Next;
		}
		free(Temp->Next);
		Temp->Next=NULL;
	}
}
void InsertAtPosition(PPNODE Head, int no, int iPos){
	int iSize=0, i=0;
	PNODE newN=NULL;
	PNODE Temp=*Head; // For insert at position
	iSize=Count(*Head); // this is call by address
	if((iPos<0) || (iPos> iSize+1)){   // invalid position
		return;
	}
	if(iPos==1){    // First position
		InsertFirst(Head,no);
	}
	else if(iPos==(iSize+1)){   // last position
		InsertLast(Head,no);
	}
	else{
		newN=(PNODE)malloc(sizeof(NODE));
		newN->Data=no;
		newN->Next=NULL;
		for(i=1;i<iPos-1;i++){
			Temp=Temp->Next;
		}
		newN->Next=Temp->Next;
		Temp->Next=newN;
		
	}
}
void DeleteAtPosition(PPNODE Head, int iPos){
	int iSize=0, i=0;
	
	PNODE Temp=*Head; // For insert at position
	PNODE Target=NULL;  // to delete
	
	iSize=Count(*Head); // this is call by address
	if((iPos<0) || (iPos> iSize)){   // invalid position
		return;
	}
	if(iPos==1){    // First position
		DeleteFirst(Head);
	}
	else if(iPos==(iSize)){   // last position
		DeleteLast(Head);
	}
	else{                  // In between
		for(i=1;i<iPos-1;i++){
			Temp=Temp->Next;
		}
		Target=Temp->Next;
		Temp->Next=Target->Next;
		free(Target);
	}
}
int main(){
	PNODE First=NULL;
	int iRet=0, iOption=1, iValue=0, iPos=0;
	// Menu Driven application
	while(iOption!=0)  {   
		printf("\n--------------------------------\n");
		printf("Enter your choice to make operations on linked list:\n");
		printf("1.Insert node at first position\n");
		printf("2.Insert node at last position\n");
		printf("3.Insert node at given position\n");
		printf("4.Delete first node\n");
		printf("5.Delete last node\n");
		printf("6.Delete from given position\n");
		printf("7.Display the contends of list\n");
		printf("8.Count the number of nodes in linked list\n");
		printf("0.Exit the application...\n");
		
		scanf("%d",&iOption);
		
		switch(iOption){
	    case 1:
            printf("Enter data to insert :\n");
			scanf("%d",&iValue);
			InsertFirst(&First,iValue);
			break;
			
		case 2:
            printf("Enter data to insert :\n");
			scanf("%d",&iValue);
			InsertLast(&First,iValue);
			break;
			
		case 3:
		    printf("Enter data to insert:\n");
			scanf("%d",&iValue);
			printf("Enter the position:\n");
			scanf("%d",&iPos);
			InsertAtPosition(&First,iValue,iPos);
			break;
		
		case 4:
			DeleteFirst(&First);
			break;
		
		case 5:
		    DeleteLast(&First);
			break;
		
		case 6:
		    printf("Enter the position to delete the node\n");
			scanf("%d",&iPos);
			DeleteAtPosition(&First,iPos);
			break;
			
		case 7:
            printf("Nodes in linked list:\n");
			Display(First);
			break;
			
			
		case 8:
		    iRet = Count(First);
            printf("Number of nodes in Linked list :%d\n",iRet);
			
			break;
		
		case 0:
            printf("Thank you for using he linked list!!!");
			break;
			
		default:
            printf("Please enter valid option:\n");
			break;
	    } // End of switch
		
	}// end of while

	return 0;
}  //end of main
