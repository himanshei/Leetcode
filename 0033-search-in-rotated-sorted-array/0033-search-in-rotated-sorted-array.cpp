class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
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
     int ind;
     if(nums[low]<nums[high]) ind=low;
     else ind=high;

     low=0,high=n-1;
     while(high-low>1){
        int mid=(high+low)/2;
        // mid=(mid+ind)%n;
        if(nums[(mid+ind)%n]>target) high=mid-1;
        else low=mid;
     }
     if(nums[(low+ind)%n]==target) return (low+ind)%n;
     else if(nums[(high+ind)%n]==target) return (high+ind)%n;
     return -1;
    }
};