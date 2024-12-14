class Solution {
public:
    void findSubsets(int index , vector<int>&arr , vector<vector<int>>&result ,vector<int>&ans){
        result.push_back(ans);
        for(int i=index ; i<arr.size();i++){
            if(i!=index && arr[i]==arr[i-1])continue;
            ans.push_back(arr[i]);
            findSubsets(i + 1 ,arr, result , ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>result;
        sort(nums.begin(), nums.end());//to get duplicates altogether
        findSubsets(0,nums ,result,ans);
        return result;       
    }
};
