//Doubly linear linked list in C++
using namespace std;
#include<iostream>
typedef struct node{
    int Data;
    struct node *Next;	
	struct node *Prev;
}NODE,*PNODE;

class DoublyLL{
	private:
	  PNODE Head;
	  int iSize;
	public:
    DoublyLL(){ // construct which get called automatically after creating object of a class
		Head=NULL;
		iSize=0;
	}	
	 void InsertFirst(int);
	 void InsertLast(int);
	 void InsertAtPos(int,int);
	 void DeleteFirst();
	 void DeleteLast();
	 void DeleteAtPos(int);
	 void Display();
	 int Count();
};

void DoublyLL::InsertFirst(int iNo){
	PNODE newN=NULL;
	newN= new NODE();
	newN->Data=iNo;
	newN->Next=NULL;
	newN->Prev=NULL;
	
	if(Head==NULL){
        Head=newN;		
	}
	else{
		newN->Next=Head;
		Head->Prev=newN;
		Head=newN;
	}
	iSize++;
}
void DoublyLL::InsertLast(int iNo){
	PNODE newN=NULL;
	PNODE Temp=Head;
	newN= new NODE();
	newN->Data=iNo;
	newN->Next=NULL;
	newN->Prev=NULL;
	
	if(Head==NULL){
		Head=newN;
	}
	else{
		while(Temp->Next!=NULL){
		    Temp=Temp->Next;
		}
        Temp->Next=newN;
		Temp->Next->Prev=Temp; // newN->Prev=Temp
		newN->Next=NULL;  // optional
	}
	iSize++;
}
void DoublyLL::InsertAtPos(int iNo,int iPos){
	PNODE newN=new NODE;
	newN->Data=iNo;
	newN->Next=NULL;
	newN->Prev=NULL;
	
	if((iPos<0)||(iPos>iSize+1)){
		return;
	}
	
	if(iPos==1){
		InsertFirst(iNo);
	}
	else if(iPos==iSize+1){
		InsertLast(iNo);
	}
	else{
		PNODE Temp=Head;
		for(int i=1;i<iPos-1;i++){
			Temp=Temp->Next;
		}
		newN->Next=Temp->Next;
		Temp->Next->Prev=newN;
		Temp->Next=newN;
		newN->Prev=Temp;
	}
}
void DoublyLL::DeleteFirst(){
	if(iSize==0){
		return;
	}
	
	if(iSize==1){
		delete Head;
		iSize=0;
	}
	else{
		Head=Head->Next;
		delete Head->Prev;
		Head->Prev=NULL;
		iSize--;
	}	
}
void DoublyLL::DeleteLast(){
     if(iSize==0){
		 return;
	 }	
	 if(iSize==1){
		 delete Head;
		 iSize=0;
	 }
	 else{
		PNODE Temp=Head;
		while(Temp->Next->Next!=NULL){
			Temp=Temp->Next;
		}
		delete Temp->Next;
		Temp->Next=NULL;
		iSize--;
	 }
}
void DoublyLL::DeleteAtPos(int iPos){	
	if((iPos<0)||(iPos>iSize+1)){
		return;
	}
	
	if(iPos==1){
		DeleteFirst();
	}
	else if(iPos==iSize+1){
		DeleteLast();
	}
	else{
		PNODE Temp=Head;
		for(int i=1;i<iPos-1;i++){
			Temp=Temp->Next;
		}
		Temp->Next=Temp->Next->Next;
		delete Temp->Next->Prev;
		Temp->Next->Prev=Temp;
	}
}
void DoublyLL::Display(){
	PNODE Temp=Head;
		while(Temp!=NULL){
			printf("|%d|<=>",Temp->Data);
			Temp=Temp->Next;
		}
		cout<<"NULL\n";
}
int DoublyLL::Count(){
	return iSize;
}
	
int main(){
	int iChoice=1, iNo=0, iPos=0;
	
	DoublyLL obj1;
	while(iChoice!=0){
		cout<<"Enter your choice:"<<"\n";
		cout<<"1:Insert at first position"<<"\n";
		cout<<"2:Insert at last position"<<"\n";
		cout<<"3:Insert at given position"<<"\n";
		cout<<"4:Delete first"<<"\n";
		cout<<"5:Delete last"<<"\n";
		cout<<"6:Delete from given positive_sign"<<"\n";
		cout<<"7:Display list"<<"\n";
		cout<<"8:count the nodes in list"<<"\n";
		cout<<"0:Exit the application"<<"\n";
		
		cin>>iChoice;
		
		switch(iChoice){
			case 1:
			    cout<<"Enter number\n";
				cin>>iNo;
				obj1.InsertFirst(iNo);
			    break;
			 
			case 2:
			    cout<<"Enter number\n";
				cin>>iNo;
				obj1.InsertLast(iNo);
			    break;
			
			case 3:
			    cout<<"Enter number\n";
				cin>>iNo;
				cout<<"Enter Position\n";
				cin>>iPos;
				obj1.InsertAtPos(iNo,iPos);
			    break;
			   
			case 4:
			    obj1.DeleteFirst();
			    break;
			   
			case 5:
			    obj1.DeleteLast();
			    break;
			   
			case 6:
				cout<<"Enter Position\n";
				cin>>iPos;
				obj1.DeleteAtPos(iPos);
			    break;
			   
			case 7:
		        obj1.Display();	
			    break;
			   
			case 8:
			    iNo=obj1.Count();
			    cout<<"Number of nodes are:"<<iNo<<"\n";
			    break;
			  
			case 0:
			    cout<<"Thank you!!!!!!!!\n";
			    break;
			  
			default:
			    cout<<"Please enter valid choice";
		}
	}
	return 0;
}