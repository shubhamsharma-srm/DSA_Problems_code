class Solution {
public:

    void findSubsets(int ind , vector<int>&nums , set<vector<int>>&result ,vector<int>&ans){
        if(ind == nums.size()){
            result.insert(ans);
            return;
        }
        ans.push_back(nums[ind]);
        findSubsets(ind + 1 ,nums , result , ans);
        ans.pop_back();
        findSubsets(ind + 1 ,nums , result , ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        set<vector<int>>result;
        sort(nums.begin(), nums.end());
        findSubsets(0,nums ,result,ans);
        vector<vector<int>>finalresult(result.begin() , result.end());
        return finalresult;       
    }
};
