#include<bits/stdc++.h>
using namespace std;

void MergeArrays(vector<int>&arr ,int low , int mid , int high){
    int left = low , right= mid+1;
    vector<int>temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    //now transfer all the elememts from temp to the original array
    for(int i =low;i<=high;i++){
        arr[i]= temp[i-low];
    }
}

void MergeSort(vector<int>&arr , int low , int high){
    if(low == high)
    return; //only one element is present

    int mid = (low+high) / 2;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    MergeArrays(arr,low,mid,high);
}

int main(){
    int n = 9;
    vector<int>arr = {3,1,5,2,1,8,9,6,4};
    MergeSort(arr , 0 , n-1);
    for(int i =0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}