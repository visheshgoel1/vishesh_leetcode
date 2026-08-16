class Solution {
public:
    long long modPow(long long a, long long n, long long mod){
        long long ans = 1;

        while(n > 0){
            if(n & 1){
                ans = ans*a%mod;
            }
            a = a*a%mod;
            n >>= 1;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        const long long MOD = 1000000007;
        long long even = (n+1)/2;
        long long odd = n/2;

        return modPow(5, even, MOD)*modPow(4, odd, MOD)%MOD;
    }
};