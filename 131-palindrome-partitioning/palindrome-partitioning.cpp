class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string& s, int l, int r){
        while(l < r){
            if(s[l++] != s[r--]){
                return false;
            }
        }
        return true;
    }

    void solve(int idx, string& s, vector<string>& path){
        if(idx == s.size()){
            ans.push_back(path);
            return;
        }

        for(int i=idx; i<s.size(); i++){

            if(isPalindrome(s, idx, i)){
                path.push_back(s.substr(idx, i - idx + 1));

                solve(i + 1, s, path);

                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        solve(0, s, path);
        return ans;
    }
};