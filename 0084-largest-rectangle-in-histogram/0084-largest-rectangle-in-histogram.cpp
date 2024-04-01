class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        vector<int>pse(n,-1);
        vector<int>nse(n,n);
        for(int i=0;i<n;i++){
            while(st.size()>0&& nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.size()>0) pse[i]=st.top();
            st.push(i);
        }
        while(st.size()>0){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
             while(st.size()>0&& nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.size()>0) nse[i]=st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int h=nums[i];
            int left=i-pse[i]-1;
            int right=nse[i]-i-1;
            ans=max(ans,(left+right+1)*h);
        }
        return ans;
    }
};