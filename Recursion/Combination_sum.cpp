class Solution {
public:

    void find_combination(int index , vector<int>&arr , vector<vector<int>>&result , vector<int>&ans ,int target){
        int n = arr.size();
        if(index == n){
            if(target == 0){
                result.push_back(ans);
            }
            return;
        }
        if(arr[index]<=target){
            ans.push_back(arr[index]);
            find_combination(index , arr , result , ans , target - arr[index]);
            ans.pop_back();
        }
        find_combination(index + 1, arr , result , ans , target);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ans;
        vector<vector<int>>result;
        find_combination(0,candidates,result,ans,target);
        return result;
        
    }
};
