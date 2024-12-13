class Solution {
public:
    //OPTIMIZED APPROACH 
    void getCombinations(int index , vector<vector<int>>&result ,vector<int>&ans , vector<int>&arr,int target){
            if(target == 0){
                result.push_back(ans);
            return;
            }
            for(int i=index;i < arr.size();i++){
                if(i>index && arr[i]==arr[i-1])continue;
                if(arr[i]>target)break;
                ans.push_back(arr[i]);
                getCombinations(i + 1,result,ans,arr,target - arr[i]);
                //pop while going back
                ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ans;
        vector<vector<int>>result;
        sort(candidates.begin(),candidates.end());
        getCombinations(0,result,ans,candidates,target); 
        return result;
    }
};
