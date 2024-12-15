class Solution {
public:
    void findPermutations(vector<int>&arr , vector<vector<int>>&result,vector<int>&ans , int freq[]){
        if(ans.size()==arr.size()){
            result.push_back(ans);
            return;
        }
        for(int i =0;i<arr.size();i++){
            if(!freq[i]){
                ans.push_back(arr[i]);
                freq[i] = 1;
                findPermutations(arr,result,ans,freq);//next recursive call  , i=1
                ans.pop_back();
                freq[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>result;
      //carry a map/hasharray to check before every recursion call if elememnt has already been taken or not
        int freq[nums.size()];//initialise everything to 0
        for(int i =0;i<nums.size();i++)freq[i]=0;
        findPermutations(nums,result,ans,freq);
        return result;
    }
};
