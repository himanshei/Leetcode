class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(high-low>1){
            int mid=(high+low)/2;
            if(nums[mid]>nums[high]) {
              low=mid+1;
            }
            else {
               high=mid;
            }

        }
         int ct=0;
         if(low+1<nums.size()&&nums[low]<nums[low+1]) ct++;
         else if(low-1>=0 &&nums[low]<nums[low-1]) ct++;
         if(ct!=0) return nums[low];
         return nums[high];
    }
};