class Solution {
public:
    int findComplement(int num) {
        if(num ==1) return 0;
        int mask = 0;
        int n = num;

        while (n) {
            mask = (mask << 1) | 1;
            n = n >> 1;
        }

        return num ^ mask;
    }
};