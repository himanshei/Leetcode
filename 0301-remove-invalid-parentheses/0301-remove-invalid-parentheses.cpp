class Solution {
public:
 int getmin(string &str){
    int ct=0,ans=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='(') ct++;
        if(str[i]==')') ct--;
        if(ct<0){
            ans++;
            ct=0;
        }
    }
    return ans+ct;
 } 
 bool isValid(string &str){
    int ct=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='(') ct++;
        if(str[i]==')') ct--;
        if(ct<0) return false;
    }
    return ct==0;
 }
 void func(int i,int x,string &temp, string &s,set<string>&st){
    if(i==s.size()){
        if(x==0 && isValid(temp)){
            st.insert(temp);
        }
        return;
    }
    if(s[i]=='('||s[i]==')'){
        if(x>0){
            func(i+1,x-1,temp,s,st);
        }
        temp+=s[i];
        func(i+1,x,temp,s,st);
        temp.pop_back();
    }else{     // for character
       temp+=s[i];
       func(i+1,x,temp,s,st);
       temp.pop_back();
    }
 }
    vector<string> removeInvalidParentheses(string s) {
        int x=getmin(s);
        set<string>st;
        string temp="";
        func(0,x,temp,s,st);
        vector<string>ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};