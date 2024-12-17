//Without using extra space - SWAP METHOD
void findPermutations(int index ,vector<int>&arr , vector<vector<int>>&result){
    if(index == arr.size()){
        result.push_back(arr);
        return;
    }

    for(int i=index ;i<arr.size();i++){
        swap(arr[index],arr[i]);
        findPermutations(index + 1,arr,result);
        swap(arr[index] ,arr[i]);

    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>result;
    findPermutations(0,nums,result);
    return result;
}
