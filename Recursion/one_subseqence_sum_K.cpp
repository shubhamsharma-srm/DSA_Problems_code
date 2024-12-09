#include <bits/stdc++.h>
using namespace std;

bool printsubwithSumK(int index , vector<int>&arr , vector<int>&subseq ,int s , int sum , int n){
    if(index == n){
        if(s == sum){
            for(auto it : subseq) cout<<it<<" ";
            cout<<endl;
            return true;
        }
        else return false;
    }
    subseq.push_back(arr[index]);
    s+=arr[index];
    if(printsubwithSumK(index + 1, arr,subseq,s,sum,n)==true){return true;}
    subseq.pop_back();
    s-=arr[index];
    if(printsubwithSumK(index+1,arr,subseq,s,sum,n)==true){
        return true;
    }
    return false;
}

int main(){
    vector<int>arr = {1,2,1};
    int n=3;
    int sum = 2;
    vector<int>subseq;
    printsubwithSumK(0,arr,subseq,0,sum,n);
    return 0;
}