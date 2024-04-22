class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        int subs=1<<n;
        for(int i=0;i<subs;i++){
              vector<int>li;
              for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    li.push_back(nums[j]);
                }
              }
              ans.push_back(li);
        }
        return ans;
    }
};