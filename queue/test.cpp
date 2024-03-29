#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> points = {{8,7},{9,9},{7,4},{9,7}};
    
    int n=points.size();
    int m=points[0].size();
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<points[i][j]<<"  ";
        }
    }
    sort(points.begin(),points.end());
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<points[i][j]<<"  ";
        }
    }
}