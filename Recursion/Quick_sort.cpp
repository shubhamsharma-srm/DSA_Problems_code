#include<bits/stdc++.h>
using namespace std;

int positionPivot(vector<int>&arr , int low , int high)
{
    int i = low , j = high;
    int pivot = arr[low];
    while(i<j)
    {
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low] , arr[j]);
    return j;
}

void QuickSort(vector<int>&arr , int low , int high)
{
    if(low <high){ // that array contains elements 
        int partition_index = positionPivot(arr , low , high);
        QuickSort(arr, low, partition_index - 1);
        QuickSort(arr, partition_index + 1,high);
    }
}

int main()
{
    int n = 9;
    vector<int>arr = {3,1,6,4,2,8,7,9,9};
    QuickSort(arr,0,n-1);
    for(int i =0;i<n;i++)
    {
        cout<<arr[i];
    }

}