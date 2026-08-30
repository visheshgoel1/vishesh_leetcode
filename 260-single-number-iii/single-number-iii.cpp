class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(int num : nums){
            x = x^num;
        }

        unsigned int bit = static_cast<unsigned int>(x) & -static_cast<unsigned int>(x);
        int a = 0;
        int b = 0;

        for(int num : nums){
            if(static_cast<unsigned int>(num) & bit){
                a = a^num;
            } else{
                b = b^num;
            }
        }
        return {a, b};
    }
};