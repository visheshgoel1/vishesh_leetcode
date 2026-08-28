class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, int target, vector<int>& candidates, vector<int>& ds){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=idx; i<candidates.size(); i++){
            if(candidates[i] > target) break;

            ds.push_back(candidates[i]);
            solve(i, target-candidates[i], candidates, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        solve(0, target, candidates, ds);
        return ans;
    }
};