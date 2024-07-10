class Solution {
public:
bool func(int mid,vector<int>&nums,int k){
    int ct=1;
    int temp=0;
    for(int i=0;i<nums.size();i++){
        if(temp+nums[i]<=mid){
            temp=temp+nums[i];
        }else{
            temp=nums[i];
            ct++;
        }
    }
    if(ct<=k) return true;
    else return false;
}
    int splitArray(vector<int>& nums, int k) {
        int sum=0;
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            mx=max(mx,nums[i]);
        }
        int low=mx,high=sum;
        while(high-low>1){
            int mid=(high+low)/2;
            if(func(mid,nums,k)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        if(func(low,nums,k)) return low;
        else return high;
    }
};