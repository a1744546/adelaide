//a1744546
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    int height = 0;
};
  
// find height of tree
int height(Node *X)
{
    if (X == NULL)
    {
        return 0;
    }else {
        return X->height;
    }
}

//find the max value
int max_value(int a, int b)
{
    if(a>b)
    {
        return a;
    }else{
        return b;
    }
}

//used to find the min value node
Node * max_node(Node* node)
{
    if (node->right == NULL) {
        return node;
    }else {
        return max_node(node->right);
    }
}
// set new node
Node* setNewNode(int value)
{
    Node* n = new Node();
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return(n);
}

//left rotate
Node *L_rot(Node *a)
{
    Node *b = a->right;
    Node *c = b->left;
    b->left = a;
    a->right = c;
  
    a->height = 1+max_value(height(a->left),height(a->right));
    b->height = 1+max_value(height(b->left),height(b->right));
  
    return b;
}
//right rotate
Node *R_rot(Node *a)
{
    Node *b = a->left;
    Node *c = b->right;
    b->right = a;
    a->left = c;
  
    a->height = 1+max_value(height(a->left),height(a->right));
    b->height = 1+max_value(height(b->left),height(b->right));
  
    return b;
}
  

  
//balance the node
int balance(Node *N)
{
    if (N == NULL)
    {
        return 0;
    }else
    {
        return height(N->left) - height(N->right);
    }
}
  


//insert a new value
Node* insert_node(Node* n, int value)
{
    if (n == NULL)
    {
        return(setNewNode(value));
    }
  
    if (value < n->value)
    {
        n->left = insert_node(n->left, value);
    }else if (value > n->value)
    {
        n->right = insert_node(n->right, value);
    }else
    {
        return n;
    }
    
    n->height = max_value(height(n->left),height(n->right))+1;
  
    int bal = balance(n);
  
    //left  rotate
    if (bal > 1 && value < n->left->value)
    {
        return R_rot(n);
    }
    // Right rotate
    if (bal < -1 && value > n->right->value)
    {
        return L_rot(n);
    }
    
    // Left Right rotate
    if (bal > 1 && value > n->left->value)
    {
        n->left = L_rot(n->left);
        return R_rot(n);
    }
  
    // Right Left rotate
    if (bal < -1 && value < n->right->value)
    {
        n->right = R_rot(n->right);
        return L_rot(n);
    }
  
    return n;
}

//used to delete node and return a new node of sub tree
Node* deleteNode(Node* n, int value)
{
      
    if (n == NULL)
    {
        return n;
    }
   
    if (  n->value > value )
    {
        n->left = deleteNode(n->left, value);
    }else if( n->value < value  )
    {
        n->right = deleteNode(n->right, value);
    }else
    {
        if( (n->left == NULL) || (n->right == NULL))
        {
            Node *node1;
  
            if(n->left)
            {
              node1 = n->left;
            }else
            {
               node1 = n->right;
            }
            
            if (node1 == NULL)
            {
                node1 = n;
                n = NULL;
            }else{
            *n = *node1;
            }
            free(node1);
        }else{
            Node* temp = max_node(n->left);
            n->value = temp->value;
            n->left = deleteNode(n->left,temp->value);
        }
    }
  
   
    if (n == NULL){
        return n;
    }
    
    n->height = 1 + max_value(height(n->left),height(n->right));
  
    int bal = balance(n);
  
    // LL rotate
    if (bal > 1 && balance(n->left) >= 0)
        return R_rot(n);
  
    // LR rotate
    if (bal > 1 && balance(n->left) < 0)
    {
        n->left = L_rot(n->left);
        return R_rot(n);
    }
  
    // RR rotate
    if (bal < -1 && balance(n->right) <= 0)
        return L_rot(n);
  
    // RL rotate
    if (bal < -1 && balance(n->right) > 0)
    {
        n->right = R_rot(n->right);
        return L_rot(n);
    }
  
    return n;
}
  
//print tree with pre order
void preorder(Node *n)
{
     if (n == NULL){
         return;
       }else{
          cout << n->value << " ";
          preorder(n->left);
          preorder(n->right);
       }
}

//print tree with post order
void post(Node* n)
{
    if (n == NULL){
        return;
    }else{
        post(n->left);
        post(n->right);
        cout<<n->value<<" ";
    }
}
  
//print the tree with inorder
void inorder(Node* n)
{
     if (n == NULL){
         return;
       }else{
           inorder(n->left);
           cout << n->value << " ";
           inorder(n->right);
       }
}
  

int main(){
    Node *n = NULL;
    vector<string> in;
    string read;
    getline(cin,read);
    string result;
    stringstream input(read);
    
    while(input>>result)
    {
        in.push_back(result);
    }
    
    for(int i=0;i<in.size();i++)
    {
        int a;
        
        if(in[i][0]=='A')
        {
            in[i].erase(0,1);
            a=stoi(in[i]);
            n = insert_node(n, a);
        }
        if(in[i][0]=='D')
        {
            in[i].erase(0,1);
            a=stoi(in[i]);
            n=deleteNode(n,a);
        }
        
        if(in[i]=="PRE")
        {
            if(n==NULL)
            {
                cout<<"EMPTY"<<endl;
            }else
            {
                preorder(n);
            }
        }
        if(in[i]=="IN")
        {
            if(n==NULL)
            {
                cout<<"EMPTY"<<endl;
            }else{
                inorder(n);
            }
        }
        if(in[i]=="POST")
        {
            if(n==NULL)
            {
                cout<<"EMPTY"<<endl;
            }else{
                post(n);
            }
        }
    }
    return 0;
}
