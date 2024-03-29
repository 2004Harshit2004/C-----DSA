#include<iostream>
#include <algorithm>
#include<queue>
#include<limits.h>
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

    void BfsDisplay(Node* root){
        queue<Node*> q;
        q.push(root);
        while(q.size()>0){
            if(q.front()->left!=NULL) q.push(q.front()->left);
            if(q.front()->right!=NULL) q.push(q.front()->right);
            cout<<q.front()->val<<" ";
            q.pop();
        }
        
    }


void construct(Node* root,int arr[],int n){
    queue<Node*>q;
    q.push(root);
    int i=1,j=2;
    while(i<n && q.size()>0){
        Node * l;
        Node * r;
        if(arr[i]==INT_MIN) l=NULL;
        else l=new Node(arr[i]);
        if(arr[j]==INT_MIN)  r=NULL;
        else if(j!=n) r=new Node(arr[j]);
        else r=NULL;
        q.front()->left=l;
        q.front()->right=r;
        q.pop();
        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);
        i+=2;j+=2;
    }
}


void printAtLevel(Node* root,int level){
    if(root==NULL) return;
    if(level==1){
        cout<<root->val<<" ";
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

void leftBoundary(Node* root){
    if(root->left==NULL && root->right==NULL) return;
    cout<<root->val<<" ";
    if(root->left!=NULL) leftBoundary(root->left);
    else{
        leftBoundary(root->right);
    }
}

void leafNode(Node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        cout<<root->val<<" ";
    }
    leafNode(root->left);
    leafNode(root->right);
}

void rightBoundary(Node* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    if(root->right!=NULL) rightBoundary(root->right);
    else rightBoundary(root->left);
    cout<<root->val<<" ";
}

void boundary(Node* root){
    leftBoundary(root);
    leafNode(root);
    rightBoundary(root->right);
}

int main(){
    int arr[]={1,7,9,2,6,INT_MIN,0,INT_MIN,INT_MIN,8,7,13,INT_MIN};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* a=new Node(arr[0]);
    construct(a,arr,n);
    levelOrderTraversal(a);
    //printing boundary of tree
    boundary(a);
}