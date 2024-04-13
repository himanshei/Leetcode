class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int j=0;
      int ct=0,ans=0;
      int n=nums.size();
      for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
           ct++;
        }
        else{
            if(k>0){
                k--;
                ct++;
            }
            else{
                while(j<n && k==0){
                    if(nums[j]==0){
                        k++;
                    }
                    ct--;
                    j++;
                }
                i--;
            }
        }
        if(k>=0)
        ans=max(ct,ans);
      }  
      return ans;
    }
};