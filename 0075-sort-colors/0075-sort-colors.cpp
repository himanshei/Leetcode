class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return;

        int st=0;
        int end=nums.size()-1;
        int i=0;

        while(i<=end && st<end){
            if(nums[i]==0){
                nums[i]=nums[st];
                nums[st]=0;
                st++;
                i++;
            }else if(nums[i]==2){
                nums[i]=nums[end];
                nums[end]=2;
                end--;
            }else{
                i++;
            }
        }
    }
};