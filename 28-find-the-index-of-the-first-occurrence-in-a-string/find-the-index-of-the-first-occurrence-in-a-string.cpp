class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;

        vector<int> lps(m);
        
        for (int i = 1, j = 0; i < m; ) {
            if (needle[i] == needle[j])
                lps[i++] = ++j;
            else if (j)
                j = lps[j - 1];
            else
                i++;
        }

        for (int i = 0, j = 0; i < n; ) {
            if (haystack[i] == needle[j]) {
                i++; j++;
                if (j == m) return i - m;
            }
            else if (j)
                j = lps[j - 1];
            else
                i++;
        }

        return -1;
    }
};