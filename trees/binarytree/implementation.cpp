#include<iostream>
#include <algorithm>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};

void display(Node* a){
    if(a==NULL){
        return; 
    } 
    cout<<a->val<<" ";
    display(a->left);
    display(a->right);
}

 int Sum(Node* root){
    if (root==NULL) return 0;
    return root->val+Sum(root->left)+Sum(root->right);
}

int findSize(Node* root){
    if(root==NULL) return 0;
    return 1+findSize(root->left)+findSize(root->right);
}

int Max(Node* root){
    if(root==NULL) return -69266662;
    return max(root->val,max(Max(root->left),Max(root->right)));
}

int level(Node* root){
    if(root==NULL) return 0;
    return 1+max(level(root->left),level(root->right));
}

int product(Node* root){
    if(root==NULL) return 1;
    return root->val*product(root->left)*product(root->right);
}

int findMin(Node* root){
    if(root==NULL) return 98;
    return min(min(findMin(root->left),findMin(root->right)),root->val);
}



int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);

    //a=root of tree
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

    display(a);
    cout<<Sum(a)<<endl;
    cout<<findSize(a)<<endl;
    cout<<Max(a)<<endl;
    cout<<level(a)<<endl;
    cout<<product(a)<<endl;
    cout<<findMin(a);
}