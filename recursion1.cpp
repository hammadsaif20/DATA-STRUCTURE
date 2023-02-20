#include<iostream>
using namespace std;


class node{

private:
int data;
node* prev;
node*next;
	
public:

void insert_head(int val);
void insert_tail(int x);
void print();
void reverse(); 
	
	
};
node*head;	
void node::insert_head(int val)
{

node* newnode=new node();
newnode->data=val;
newnode->next=NULL;
newnode->prev=NULL;	
	


if(head == NULL)
{
  head=newnode;
  
}
else{
	
 head->prev=newnode;
 newnode->next=head;
 head=newnode;		
}
}
void node::print()
{
  node* temp=head;
 
 
 while(temp!=NULL)
 {
 	cout<<temp->data;
 	temp=temp->next;
 }
	
	
}

void node::reverse()
{
	node*tmp=head;
	
if(tmp==NULL){
	return;
}	

while(tmp->next!=NULL)
{
	tmp=tmp->next;	
}
while(tmp!=NULL)
{
	cout<<tmp->data;
	tmp=tmp->prev;
}
	
	
}

 main()
{
node*head=NULL;
	
	
node dlist;

dlist.insert_tail(10);
dlist.insert_head(30);
dlist.insert_head(40);
dlist.insert_head(50);

dlist.print();
	
	
	
}

