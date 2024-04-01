class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        stack<int>st;
        st.push(0);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(0);
            }
            else{
                int a =st.top();
                st.pop();
                if(a==0) a=1;
                else a=2*a;
                st.top()+=a;
            }
        }
        return st.top();
    }
};