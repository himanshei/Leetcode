class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        bitset<31>a1(left),a2(right);
        string s1=a1.to_string();
        string s2=a2.to_string();
        int ans=0;
        for(int i=0;i<31;i++){
            if(s1[i]=='1'&& s2[i]=='1'){
                ans=ans+(1<<(30-i));
            }
            if(s1[i]=='0'&& s2[i]=='1') break;
        }
        return ans;
    }
};