#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int> mp;
    pair<string,int> hg;
    hg.first="hggoswami";
    hg.second=30;
    //cout<<hg.first;
    //cout<<hg.second;
    pair<string,int> my;
    my.first="mohit";
    my.second=52;
    pair<string,int> gt;
    gt.first="gourav";
    gt.second=29;
    mp.insert(hg);
    mp.insert(my);
    mp.insert(gt);
    for(pair<string,int> ele:mp){
        cout<<ele.first<<" "<<ele.second;
        cout<<endl;
    }

    cout<<mp.size()<<endl;

    for(auto ele:mp){
        cout<<ele.first<<" "<<ele.second;
        cout<<endl;
    }

    cout<<mp.size()<<endl;

    mp["abhay"]=3;
    mp["chintan"]=21;
    for(auto ele:mp){
        cout<<ele.first<<" "<<ele.second;
        cout<<endl;
    }

    cout<<mp.size()<<endl;

    mp.erase("gourav");
    mp.erase("abhay");
    mp.erase("chintan");
    mp.erase("devi");
    for(auto ele:mp){
        cout<<ele.first<<" "<<ele.second;
        cout<<endl;
    }
    cout<<mp.size();
}