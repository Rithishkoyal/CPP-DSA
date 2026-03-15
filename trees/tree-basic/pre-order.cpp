#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
//Recursive soln

void preOrder(Node* root){
    
    if(root==NULL){
        return;
    }
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
}

//Iterative Soln

void iterativepreOrder(Node* root){
    cout<<"Iterative soln"<<endl; 
    // if root is NULL, then return
    if(root==NULL){
        return;
    }
    // create a stack to store nodes
    stack<Node*>st;
    // initialize current node to root
    Node* curr = root;
    // loop until current node is NULL and stack is empty
    while(curr!=NULL || !st.empty()){
        // loop until current node is NULL
        while(curr!=NULL){
            // push current node to stack
            st.push(curr);
            // move to left subtree
            curr = curr->left;
        }
        // pop top node from stack
        curr=st.top();
        st.pop();
        // print data of current node
        cout<<curr->data<<" ";
        // move to right subtree
        curr = curr->right;
    }
}


int main()
{
    Node* root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5); 
   preOrder(root);
  iterativepreOrder(root);

    return 0;
}