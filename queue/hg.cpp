#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    //vector<vector<int>> ans;
    //vector<vector<int>> ans;
        vector<int> nums={8,8,8,8,2,4,4,2,4};
        int n=nums.size();
        unordered_map<int,int> hg;
        for(int i=0;i<n;++i){
            hg[nums[i]]++;
        }
        for(auto ele:hg){
            cout<<ele.first<<" "<<ele.second<<endl;
        }
}