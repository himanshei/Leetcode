class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int i = nums.size();
        for(int l = 0; l<nums.size(); l++){
            if(nums[l]>=0){
                i = l;
                break;
            }
        }
        int j = i-1;
        while(i<n && j>=0){
            if((nums[i]*nums[i])<(nums[j]*nums[j])){
                ans.push_back(nums[i]*nums[i]);
                i++;
            }
            else{
                ans.push_back(nums[j]*nums[j]);
                j--;
            }
        }
        while(i<n){
            ans.push_back(nums[i]*nums[i]);
            i++;
        }
        while(j>=0){
            ans.push_back(nums[j]*nums[j]);
            j--;
        }
        return ans;
    }

    
};