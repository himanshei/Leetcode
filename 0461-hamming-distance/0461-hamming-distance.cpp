class Solution {
public:
    int hammingDistance(int x, int y) {
        int ct=0;
        while(x>0 ||y>0){
            if((x&1)!=(y&1)) ct++;
            x=(x>>1); //right shift x to get the next bit
            y=(y>>1);
        }
        return ct;
    }
};