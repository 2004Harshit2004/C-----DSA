#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    string s ="aada";
    unordered_map<char,vector<int>>hg;
        int count=1;
        for(int i=1;i<s.size();++i){
            if(s[i]==s[i-1]) count++;
            else{
                //if(i==s.size()-1) count++;
                vector<int>v;
                if(hg.find(s[i-1])!=hg.end()){
                    v=hg[s[i-1]];
                    v.push_back(count);
                }
                else{
                    v.push_back(count);
                }
                hg[s[i-1]]=v;
                count=1;
            }
            if(i==s.size()-1){
                //if(i==s.size()-1) count++;
                vector<int>v;
                if(hg.find(s[i])!=hg.end()){
                    v=hg[s[i]];
                    v.push_back(count);
                }
                else{
                    v.push_back(count);
                }
                hg[s[i]]=v;
                count=1;
            }
            
        }
        cout<<hg.size();
        for(auto ele:hg){
            cout<<ele.first<<" ";
            vector<int>v;
            v=ele.second;
            for(int i=0;i<v.size();++i){ cout<<v[i]<<endl;}
        }
}