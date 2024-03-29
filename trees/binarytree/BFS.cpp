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

void printAtLevel(Node* root,int level){
    if(root==NULL) return;
    if(level==1){
        cout<<root->val;
        return;
    }
    printAtLevel(root->left,level-1);
    printAtLevel(root->right,level-1);
}

int level(Node* root){
    if(root==NULL) return 0;
    return 1+max(level(root->left),level(root->right));
}

void levelOrderTraversal(Node* root){
    int n=level(root);
    for(int i=1;i<=n;++i){
        printAtLevel(root,i);
        cout<<endl;
    }
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
    levelOrderTraversal(a);
}