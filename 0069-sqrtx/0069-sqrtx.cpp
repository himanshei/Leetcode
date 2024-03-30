class Solution {
public:
    int mySqrt(int x) {

        long long low=0,high=x;
            while(high-low>1){
                long long mid=(high+low)/2;
                if(mid*mid<=x){
                    low=mid;
                }
                else{
                    high=mid-1;
                }  
            }
        if(high*high<=x) return high;
        return low;
    }
};