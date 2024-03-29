#include<iostream>
#include <algorithm>
#include<limits.h>
#include<queue>
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

int main(){
    int arr[]={1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    Node* a=new Node(arr[0]);
    construct(a,arr,n);
    display(a);
    cout<<endl;
}