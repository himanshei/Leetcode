class Solution {
public:
    bool isPowerOfFour(int n) {
     if(__builtin_popcount(n)==1 && __builtin_ctz(n)%2==0) return true;
     return false;
    }
};