#include <iostream>
#include<stdio.h>
#include<malloc.h> // for free
#include<stdlib.h>
#include <stack>
using namespace std;

struct node {
	node* right;
	node* left;
	int data;
};

// add a node to the tree
node* insert(node* &t, int value)
{
	
	if (t == NULL) {
		t = new node;
		t->data = value;
		t->left = NULL;
		t->right = NULL;
	} else {
		if (value < t->data) 
			insert(t->left, value);
		else insert(t->right, value);
	}

	return t;
}

// searches for a value and returns a pointer to the node if found

struct node * search(struct node* root, int key){
    while(root!=NULL){
        if(key == root->data){
            return root;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}

//max value
node*max(node*root)
{
	if(root->right==NULL)
	{
		return root;
	}
else if(root->right!=NULL)
{
return max(root->right);
}
}



// inOrder traversal
/*void inOrder(node* t)
{
	if (t != NULL) {
		inOrder(t->left);
		cout << t->data << " ";
		inOrder(t->right);
	}
}*/
 
   // preOrder traversal
void preOrder(node* t)
{
	if (t != NULL) {
		cout << t->data << " ";
		preOrder(t->left);
		preOrder(t->right);
	}
}



struct node * inorderIterative(node* root)
{
    // create an empty stack
    stack<node*> stack;
 
    // start from the root node (set current node to the root node)
    node* curr = root;
 
    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || curr != NULL)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != NULL)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";
 
            curr = curr->right;
        }
    }
}

// postOrder traversal
void postOrder(node* t)
{
	if (t != NULL) {
		postOrder(t->left);
		postOrder(t->right);
		cout << t->data << " ";
	}
}

void destroyTree(node* t)
{
	if (t != NULL) {
		destroyTree(t->left);
		destroyTree(t->right);
	}

	delete t;
}

struct node *inOrderPredecessor(struct node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value){

    struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }

    //searching for the node to be deleted
    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}


int main()
{
	node* root = NULL;

	// test insert
	insert(root, 50);
  insert(root, 19);
  insert(root, 28);
  insert(root, 40);
  insert(root, 16);
  insert(root, 70);
  insert(root, 55);
  insert(root, 56);
  insert(root, 17);
  insert(root, 90);
  
  
  
  
  cout<<"\n MIN---VALUE";
 cout<< max(root)->data;
	
	//test search
	/*if (search(root, 11) == NULL) 
		cout<<"No records returned\n";
	else cout<<"found it\n";
	*/
 cout<<"\n----------------------------------------------------------------------------";

	


	
// test inOrder traversal
	cout<<"\ninOrder_Iterative: ";
	inorderIterative(root);

 
 cout<<"\n----------------------------------------------------------------------------";

 // test preOrder traversal
	cout<<"\npreOrder: ";
	preOrder(root);
	
 cout<<"\n----------------------------------------------------------------------------";
	// test postOrder traversal
	cout<<"\npostOrder: ";
	postOrder(root);
	
 cout<<"\n----------------------------------------------------------------------------";

	//delete
	cout<<"\n";
	cout<<"\n[-deleted node-]:";
	cout<<"\n";
	deleteNode(root,70);
	
// test inOrder traversal
	cout<<"\ninOrder_iterative: ";
	inorderIterative(root);

 
 cout<<"\n----------------------------------------------------------------------------";

 // test preOrder traversal
	cout<<"\npreOrder: ";
	preOrder(root);
	
 cout<<"\n----------------------------------------------------------------------------";
	// test postOrder traversal
	cout<<"\npostOrder: ";
	postOrder(root);
	
 cout<<"\n----------------------------------------------------------------------------";
	
		
 cout<<"\n----------------------------------------------------------------------------";
	
	
	// empty the tree
	destroyTree(root);
	

	

	return 0;
}
