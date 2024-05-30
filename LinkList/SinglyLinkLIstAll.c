#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();

struct node {
	int data;
	struct node* next;
};

struct node* head =0;

int main(){
	   
        int choice;
        
                printf("\n\t\t************MENU**************\n");
                printf("\n 1.Create     \n");
                printf("\n 2.Display    \n");
                printf("\n 3.Insert at the beginning    \n");
                printf("\n 4.Insert at the end  \n");
                printf("\n 5.Insert at specified position       \n");
                printf("\n 6.Delete from beginning      \n");
                printf("\n 7.Delete from the end        \n");
                printf("\n 8.Delete from specified position     \n");
                printf("\n 9.Exit       \n");
                printf("\n--------------------------------------\n");
                
        while(1){                    
               printf("\nEnter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3: 
                                        insert_begin();
                                        break;
                        case 4:
                                        insert_end();
                                        break;
                        case 5:
                                        insert_pos();
                                        break;
                        case 6:
                                        delete_begin();
                                        break;
                        case 7:
                                        delete_end();
                                        break;
                        case 8:
                                        delete_pos();
                                        break;
                        
                        case 9:
                                        exit(0);
                                        break;
                             
                        default:
                                        printf(" Wrong Choice");
                                        break;
                }
        }
        return 0;
}

void create(){
	struct node* temp, *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	
	if(newnode==NULL){
		printf("\nOut of Memory Space:");
        exit(0);
	}
	printf("Enter the data value for the node:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    
    if(head==0){
    	head=newnode;
	}
	else{
		 temp=head;                              
                while(temp->next!=NULL)
                {
                        temp=temp->next;
                }
                temp->next=newnode;
	}
}

void display(){
	 struct node* temp;
        if(head==NULL)
        {
                printf("\nList is empty:");
                return;
        }
        else
        {
                temp=head;
                printf("\nThe List elements are:");
                while(temp->next!=NULL)                   
		                                            
                {
                        printf("%d\t",temp->data );
                        temp=temp->next ;
                }
        }
}


void insert_begin()
{
        struct node *temp ,*newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
                printf("\nOut of Memory Space:");
                return;
        }
        printf("\nEnter the data value for the node:" );
        scanf("%d",&newnode->data);
        newnode->next =NULL;
        if(newnode==NULL)
        {
                newnode=head;
        }
        else
        {
                newnode->next=head;
                head=newnode;
        }
}
void insert_end()
{
        struct node *newnode,*temp;
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
                printf("\nOut of Memory Space:");
                return;
        }
        printf("\nEnter the data value for the node:" );
        scanf("%d",&newnode->data );
        newnode->next =NULL;
        if(head==NULL)
        {
                head=newnode;
        }
        else
        {
                temp=head;
                while(temp->next !=NULL)
                {
                        temp=temp->next ;
                }
                temp->next =newnode;
        }
}
void insert_pos()
{
        struct node *newnode,*temp;
        int i,pos;
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
                printf("\nOut of Memory Space:");
                return;
        }
        printf("\nEnter the position for the new node to be inserted:");
        scanf("%d",&pos);
        printf("\nEnter the data value of the node:");
        scanf("%d",&newnode->data) ;
  
        newnode->next=NULL;
        if(pos==0)
        {
                newnode->next=head;
                head=newnode;
        }
        else
        {
                for(i=0,temp=head;i<pos-1;i++) { temp=temp->next;
                        if(newnode==NULL)
                        {
                                printf("\nPosition not found:[Handle with care]");
                                return;
                        }
                }
                newnode->next =temp->next ;
                temp->next=newnode;
        }
}
void delete_begin()
{
        struct node *ptr;
        if(head==NULL)
        {
                printf("\nList is Empty:");
                return;
        }
        else
        {
                ptr=head;
                head=head->next ;
                printf("\nThe deleted element is :%d",ptr->data);
                free(ptr);
        }
}
void delete_end()
{
        struct node *temp,*ptr;
        if(head==NULL)
        {
                printf("List is Empty:");
                exit(0);
        }
        else if(head->next ==NULL)
        {
                ptr=head;
                head=NULL;
                printf("\nThe deleted element is:%d",ptr->data);
                free(ptr);
        }
        else
        {
                ptr=head;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("\nThe deleted element is:%d",ptr->data);
                free(ptr);
        }
}
void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(head==NULL)
        {
                printf("\nThe List is Empty:");
                exit(0);
        }
        else
        {
                printf("\nEnter the position of the node to be deleted:");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=head;
                        head=head->next ;
                        printf("\nThe deleted element is:%d",ptr->data  );
                        free(ptr);
                }
                else
                {
                        ptr=head;
                        for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found:");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted element is:%d",ptr->data );
                        free(ptr);
                }
        }
}
