#include<iostream>
#include<queue>

using namespace std;

int main(){
    //max Heap
    // priority_queue<int> mxH;
    // mxH.push(9);
    // mxH.push(2);
    // mxH.push(3);
    // mxH.push(12);
    // mxH.push(8);
    // cout<<mxH.top()<<endl;
    // mxH.pop();
    // cout<<mxH.top()<<endl;

    //min Heap
    // priority_queue<int,vector<int>,greater<int>> mnH;
    // mnH.push(8);
    // mnH.push(1);
    // mnH.push(5);
    // mnH.push(3);
    // cout<<mnH.top()<<endl;
    // mnH.pop();
    // cout<<mnH.top()<<endl;

    // min heap intailizing with vector
    vector<int> v={1,2,3,4,5};
    priority_queue<int,vector<int>,greater<int>> mn(v.begin(),v.end());
    cout<<mn.top()<<endl;
    mn.pop();
    cout<<mn.top()<<endl;

    // min heap intailizing with array
    int arr[]={3,2,1,6,5};
    priority_queue<int> mx(arr,arr+5);
    cout<<mx.top()<<endl;
    mx.pop();
    cout<<mx.top()<<endl;

}