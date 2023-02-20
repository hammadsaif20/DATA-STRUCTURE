#include <iostream>
using namespace std;

//This represents my tree node
struct node{
    int value;
    node *left,*right;
};

//minimum value of bst
node* minValue(node* tnode){
    if(tnode->left!=NULL){
        return minValue(tnode->left);
    }
    else{
        return tnode;
    }

}

//Inorder traversal
void inorder(node *tnode){
    if(tnode->left!=NULL){
        inorder(tnode->left);
    }
    cout<<tnode->value;
    if(tnode->right!=NULL){
        inorder(tnode->right);
    }

}

//insert function
/*{           // root node
	struct node*p;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=2;
	p->left=null;
	p->right=null;
}
{             //first node
	struct node*p1;
	p1=(struct node*)malloc(sizeof(struct node));
	p->data=5;
	p1->left=null;
	p1->right=null;
}{           //secouund node
	struct node*p2;
	p2=(struct node*)malloc(sizeof(struct node));
	p->data=3;
	p2->left=null;
	p2->right=null;
}
{
          //linking the root node with left and right child ;
	p->left=p1;
	p->right=p2;
	
return 0;	
}*/
struct node* insert(int val,node *tnode){
    node *temp=tnode;
    if(temp==NULL){       //creating node 
        temp= new node;
        temp->value=val;
        temp->left=NULL;
        temp->right=NULL;
    }
    else if(val<temp->value){
        temp->left=insert(val,temp->left);
    }
    else if(val>temp->value){
        temp->right=insert(val,temp->right);
    }

    return temp;
} int main()
{
	struct node *p=insert(2);
		struct node *p1=insert(4);
		 	struct node *p2=insert(5);
		 	 p->left=p1;    //linking the node
		 	 p->right=p2;
		 	 
	
}

//delete function
node* deleteNode(node* tnode,int val){

    if(tnode==NULL) 
        return tnode;
    if(tnode->value>val){
        tnode->left=deleteNode(tnode->left,val);
    }
    else if(tnode->value<val){
        tnode->right=deleteNode(tnode->right,val);
    }
    else{
        if(tnode->left==NULL){
            node* temp=tnode->right;
            delete tnode;
            return temp;
        }
        else if(tnode->right==NULL){
            node* temp=tnode->left;
            delete tnode;
            return temp;
        }
        node* temp=minValue(tnode->right);
        tnode->value=temp->value;       
        tnode->right=deleteNode(tnode->right,temp->value);
    }
    return tnode;

}
int main(){
cout<<"Binary Tree";
node *ROOT=NULL;
ROOT=insert(3,NULL);
insert(2,ROOT);
insert(5,ROOT);
insert(4,ROOT);
insert(1,ROOT);
insert(7,ROOT);
insert(8,ROOT);
deleteNode(ROOT,3);
inorder(ROOT);
return 0;
}
