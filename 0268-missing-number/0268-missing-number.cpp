class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        for(auto it:nums){
            ans=ans^it;
        }
        int n=nums.size();
        for(int i=0;i<=n;i++){
            ans=ans^i;
        }
        return ans;
    }
};