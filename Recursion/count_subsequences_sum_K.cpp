#include <bits/stdc++.h>
using namespace std;

int printsubwithSumK(int index , vector<int>&arr ,int s , int sum , int n){
    if(index == n){
        if(s == sum){
            return 1;
        }
        return 0;
    }
    s+=arr[index];
   int l= printsubwithSumK(index + 1, arr,s,sum,n);
    s-=arr[index];
    int r= printsubwithSumK(index+1,arr,s,sum,n);

    return l+r;
}

int main(){
    vector<int>arr = {1,2,1};
    int n=3;
    int sum = 2;
    vector<int>subseq;
   cout<< printsubwithSumK(0,arr,0,sum,n);
    return 0;
}