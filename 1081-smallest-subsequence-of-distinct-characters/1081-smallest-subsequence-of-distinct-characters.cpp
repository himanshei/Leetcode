class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        vector<int>vis(27,0);
        vector<int>last_index(27,0);
        for(int i=0;i<s.size();i++){
            last_index[s[i]-'a']=i;
        }
        stack<char>st;
        for(int i=0;i<n;i++){
            if(vis[s[i]-'a']==1) continue;
            while(st.size()>0 && st.top()>s[i] && i<last_index[st.top()-'a']){
                vis[st.top()-'a']=0;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]-'a']=1;
        }
        string res="";
        while(st.size()>0){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};