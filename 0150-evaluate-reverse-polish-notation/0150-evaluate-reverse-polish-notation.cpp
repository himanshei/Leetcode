class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(tokens[i]=="+")st.push(a+b);
                else if(tokens[i]=="-")st.push(b-a);
                else if(tokens[i]=="*")st.push(a*b);
                else st.push(b/a);

            }
            else{
                int d=stoi(tokens[i]);
                st.push(d);
            }
        }
        return st.top();

    }
};