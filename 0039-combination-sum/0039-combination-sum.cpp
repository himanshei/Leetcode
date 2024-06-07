class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& A, int B) {
        sort(A.begin(),A.end());
        set<int>s(A.begin(),A.end());
        A.assign(s.begin(),s.end());
        vector<int>v;
        func(A,B,v,0);
        return ans;
    }
    void func(vector<int>&A,int B,vector<int>&v,int i){
        if(B==0){
            ans.push_back(v);
        }
        while(i<A.size()&& B-A[i]>=0){
            v.push_back(A[i]);
            func(A,B-A[i],v,i);
            i++;
            v.pop_back();
        }
    }
    
};