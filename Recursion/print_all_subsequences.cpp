#include <bits/stdc++.h>
using namespace std;

void printsub(int index , vector<int>&arr , vector<int>&subseq ,int n){
    if(index==n){
        for(auto it : subseq){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    subseq.push_back(arr[index]);
    printsub(index +1,arr,subseq,n);
    subseq.pop_back();
    printsub(index +1, arr, subseq,n);

}
int main(){

    vector<int>arr = {1 , 2, 1 ,3};
    int n=4;
    vector<int>subseq;
    printsub(0,arr,subseq,n);
    return 0;
}
