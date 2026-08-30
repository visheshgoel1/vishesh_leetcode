class Solution {
public:
    void solve(int idx, vector<vector<int>>& ans, vector<int>& nums){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx], nums[i]);
            solve(idx+1, ans, nums);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, ans, nums);
        return ans;
    }
};