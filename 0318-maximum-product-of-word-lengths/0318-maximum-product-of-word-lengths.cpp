class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> v1(n+1,0);
        for(int i=0;i<n;i++){
            string s = words[i];
            for(int j=0;j<s.size();j++)
                v1[i] = v1[i]|(1<<(s[j]-'a'));
        }
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if((v1[i] & v1[j])==0){
                    int d= words[i].size()*words[j].size();
                    ans =max(ans,d);
                }
            }
        }
        return ans;
    }
};