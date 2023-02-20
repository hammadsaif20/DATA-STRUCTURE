
// creating nodeee

 // root node
 /*{
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



struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}
int main(){
    /*
    // Constructing the root node
    struct node *p;
    p = (struct node *) malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    // Constructing the second node
    struct node *p1;
    p1 = (struct node *) malloc(sizeof(struct node));
    p->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    // Constructing the third node
    struct node *p2;
    p2 = (struct node *) malloc(sizeof(struct node));
    p->data = 4;
    p2->left = NULL;
    p2->right = NULL;
    */
   
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(2);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    return 0;
    
//insertion

 struct node* insert(int val,node *tnode){
    node *temp=tnode;
    if(temp==NULL){
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
}


// PRE-ORDER
void preOrder(struct  node* root){
    if(root!=NULL){
        cout<<root->data;
        preOrder(root->left);
        preOrder(root->right);
    }
}
//POST-ORDER
void preOrder(struct  node* root){
    if(root!=NULL){
         preOrder(root->left);
        preOrder(root->right);
       cout<<root->data;
    }
}

//IN-ORDER
 void inorder(struct node* root)
 {
 	
 	if(root!=null)
 	{
 		inorder(root->left)
 		cout<<root->data;
 		inorder(root->right);
 		
 	}
struct node *n=search(p,3)
if(n!=null)
{
	cout<<n->data;
	
}
else(
      cout<<"element not found";
      
)


//search

struct node * search(struct node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

//deletion
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
    }

    //searching for the node to be deleted
    if (value < root->data){
        deleteNode(root->left,value);
    }
    else if (value > root->data){
        deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        deleteNode(root->left, iPre->data);
    }
}



