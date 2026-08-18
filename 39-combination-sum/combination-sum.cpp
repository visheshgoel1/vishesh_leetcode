class Solution {
public:
    void solve(int i, int target, vector<int>& a, vector<int>& curr, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        if(i == a.size() || a[i]>target){
            return;
        }

        curr.push_back(a[i]);
        solve(i, target - a[i], a, curr, ans);
        curr.pop_back();

        solve(i + 1, target, a, curr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, target, candidates, curr, ans);
        return ans;
    }
};