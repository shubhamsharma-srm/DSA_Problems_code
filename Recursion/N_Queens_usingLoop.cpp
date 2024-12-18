// Must = do question
class Solution {
public:
    //not efficient
    bool isSafe(int row , int col , vector<string>ans , int n){
        int duplicateRow = row;
        int duplicateCol = col;

        //checking upper diagnol (row and col both decreases)
        while(row >=0 && col>=0){
            if(ans[row][col] == 'Q')return false;
            row--;
            col--;
        }
        row = duplicateRow;
        col = duplicateCol;
        //checking the columns to the left
        while(col>=0){
            if(ans[row][col] =='Q')return false;
            col--;
        }
        row = duplicateRow;
        col = duplicateCol;
        //checking the lower diagonal(row increases but col decreases)
        while(row<n && col>=0){
            if(ans[row][col] == 'Q')return false;
            row++;
            col--;
        }
        //if none condition satisfies (queen is safe)
        return true;
    }

    void Solve(int col , vector<string>&ans , vector<vector<string>>&result , int n){
        if(col == n){
            result.push_back(ans);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row , col , ans, n)){
                ans[row][col] = 'Q';
                Solve(col+1,ans,result,n);
                //backtrack
                ans[row][col]= '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>result;
        vector<string>ans(n);
        string s(n,'.');
        for(int i= 0;i<n;i++){
            ans[i]= s;
        }
        Solve(0,ans,result,n);
        return result;
        
    }
};
