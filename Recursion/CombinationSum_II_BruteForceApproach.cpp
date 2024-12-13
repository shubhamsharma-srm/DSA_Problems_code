class Solution {
public:
    //BRUTE FORCE APPROACH 
    void getCombinations(int index , set<vector<int>>&result ,vector<int>&ans , vector<int>&arr,int target){
        int n = arr.size();
        if(index==n){
            if(target == 0){
                result.insert(ans);
            }
            return;
        }
        if(arr[index]<=target){
            ans.push_back(arr[index]);
            getCombinations(index + 1,result,ans,arr,target - arr[index]);
            //pop while going back
            ans.pop_back();
        }
        //not take condition
        getCombinations(index+1,result,ans,arr,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ans;
        set<vector<int>>result;
        sort(candidates.begin(),candidates.end());
        getCombinations(0,result,ans,candidates,target); 
        vector<vector<int>>finalResult(result.begin(),result.end());
        return finalResult;
    }
};
