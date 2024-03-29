#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> s;
    s.insert(2);
    s.insert(9);
    s.insert(3);
    s.insert(52);
    s.insert(2);
    s.insert(9);
    s.insert(3);
    s.insert(52);
    s.insert(92);
    s.insert(34);
    s.insert(2);
    cout<<s.size()<<endl;
    // for each loop
    for(int ele:s){
        cout<<ele<<" ";
    }
    cout<<endl;

    int target=52;
    //finding a target in the set
    // s.find(tar) searches tar in the set
    // if it is not founded then it return last element
    if(s.find(target)!=s.end()){
        cout<<"target exists";
    } 
    else cout<<"target does not exists";

}