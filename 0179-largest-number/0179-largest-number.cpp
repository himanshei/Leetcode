class Solution {
public:
    bool static cmp(string a, string b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string>V(n);
        for(int i=0;i<n;i++){
            V[i]=to_string(nums[i]);
        }
        sort(V.begin(),V.end(),cmp);
        string ans="";
        for(int i=0;i<n;i++){
            ans=ans+V[i];
        }
         if (ans[0] == '0') {
            return "0";
        }
        return ans;
    }
};