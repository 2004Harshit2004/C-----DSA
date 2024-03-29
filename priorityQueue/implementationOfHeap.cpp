#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class MaxHeap{
    public:
    vector<int> v;
    
    bool empty(){
        return v.size()==0;
    }

    void push(int n){
        v.push_back(n);
        int ci=v.size()-1;
        while(ci>0){
            int pi=(ci-1)/2;
            if(v[ci]>v[pi]){
                swap(v[pi],v[ci]);
                ci=pi;
            }
            else break;
        }
    }

    void pop(){
        if(v.size()==0) return;
        swap(v[0],v[v.size()-1]);
        v.pop_back();
        int idx=0;
        while(1){
            int maxE=idx;
            int lci=2*idx+1;
            int rci=2*idx+2;
            if(lci>=v.size()) return;
            if(v[maxE]<v[lci]){
                maxE=lci;
            }
            if(rci<v.size() && v[maxE]<v[rci]){
                maxE=rci;
            }
            if(maxE!=idx){
                swap(v[idx],v[maxE]);
                idx=maxE;
            }
            else return;
        }
    }

    void remove(int n){
        int idx=n;
        while(1){    
            int lci=2*n+1;
            int rci=2*n+2;
            if(lci>v.size()) break;
            if(v[lci]>v[rci]){
                swap(v[lci],v[idx]);
                idx=lci;
            }
            else{
                swap(v[rci],v[idx]);
                idx=rci;
            }
        }

    }

    int peek(){
        if(v.size()==0) return -1;
        else return v[0];
    }

    void display(){
        cout<<"[";
        for(int i=0;i<v.size();++i){
            cout<<v[i]<<",";
        }
        cout<<"]"<<endl;
    }

};

class MinHeap{
    vector<int> v;
    public:

    MinHeap(vector<int> hg){
        v=hg;
        int n=hg.size();
        // for(int i=0;i<hg.size();++i){
        //     upheapify(i);
        // }
        for(int i=n/2;i>=0;--i){
            downheapify(i);
        }
    }

    bool empty(){
        return v.size()==0;
    }

    void upheapify(int idx){
        while(idx>0){
            int pi=(idx-1)/2;
            if(v[pi]>v[idx]){
                swap(v[pi],v[idx]);
                idx=pi;
            }
            else return;
        }
    }

    void push(int ele){
        v.push_back(ele);
        upheapify(v.size()-1);
    }

    void downheapify(int idx){
        while(idx<v.size()){
            int minE=idx;
            int lci=2*idx+1;
            int rci=2*idx+2;
            if(lci>=v.size()) return;
            if(v[minE]>v[lci]){
                minE=lci;
            }
            if(rci<v.size() && v[rci]<v[minE]){
                minE=rci;
            }
            if(minE!=idx){
                swap(v[minE],v[idx]);
                idx=minE;
            }
            else return;
        }
    }

    //removing highest priority element of heap
    void pop(){
        if(v.size()==0) return;
        swap(v[0],v[v.size()-1]);
        v.pop_back();
        downheapify(0);
    }

    //removing element of a specific index
    void remove(int idx){
        v[idx]=INT_MIN;
        upheapify(idx);
        swap(v[0],v[v.size()-1]);
        v.pop_back();
        downheapify(0);
    }


    //return highest priority element of heap
    int peek(){
        if(v.size()==0) return -1;
        else return v[0];
    }

    void display(){
        cout<<"[";
        for(int i=0;i<v.size();++i){
            cout<<v[i]<<",";
        }
        cout<<"]"<<endl;
    }

};

int main(){
    vector<int> v={9,6,1,19,3,2,8,12,5};
    MinHeap mh(v);
    mh.display();
}