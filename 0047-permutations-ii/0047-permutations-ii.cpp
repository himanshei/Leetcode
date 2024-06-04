class Solution {
public:
    void func(vector<int>&vis,vector<int>&nums,vector<int>&temp,set<vector<int>>&st){
        int flag=0;
        for(int  i= 0;i<nums.size();i++){
            if(vis[i]==0) flag++;  //vis=0 means more elements are left to visit and the flag will increment by 1 then
        }
        if(flag==0){                   //if flag is 0 means all the elements are visited 
            st.insert(temp);
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i]==1) continue;
            temp.push_back(nums[i]);
            vis[i]=1;
            func(vis,nums,temp,st);
            vis[i]=0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
        vector<int>temp;
        int n=nums.size();
        vector<int>vis(n,0);
        func(vis,nums,temp,st);
        vector<vector<int>>ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};