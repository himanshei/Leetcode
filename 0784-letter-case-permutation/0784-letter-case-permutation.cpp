class Solution {
public:
    void func(int i,string &temp,vector<string>&ans,string&s){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        if(!isalpha(s[i])){
            temp+=s[i];
            func(i+1,temp,ans,s);
            temp.pop_back();
        }
        else{
            char c= toupper(s[i]);
            char d= tolower(s[i]);
            temp+=c;
            func(i+1,temp,ans,s);
            temp.pop_back();
            temp+=d;
            func(i+1,temp,ans,s);
            temp.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
       string temp="";
       vector<string>ans;
       func(0,temp,ans,s);
       return ans; 
    }
};