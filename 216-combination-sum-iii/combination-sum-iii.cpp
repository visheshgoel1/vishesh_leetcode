class Solution {
public:
    vector<vector<int>> ans;
    void solve(int start, int k, int n, vector<int>& ds){
        if(k==0){
            if(n==0){
                ans.push_back(ds);
            return;
            }
        }
        for(int i=start; i<=9; i++){
            if(i > n) break;
            ds.push_back(i);
            solve(i+1, k-1, n-i, ds);
            ds.pop_back();
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        solve(1, k, n, ds);
        return ans;
    }
};