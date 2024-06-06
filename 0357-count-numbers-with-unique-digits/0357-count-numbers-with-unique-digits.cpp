class Solution {
public:
    int func(int i,vector<bool>&vis,int n){
        if(i==0){
            return 1;
        }
        int ans=0;
        int d=0;
        if(i==n){            //checking if the i and n are equal if they are means its the first positiion and 0 can be at the first position
            d++;             //making d to start as 1 if its the first position i.e. i and n are equal
        }
        for(int j=d;j<=9;j++){
            if(vis[j]==1) continue;
            vis[j]=1;
            ans=ans+func(i-1,vis,n);
            vis[j]=0;           //backtracking
        }
          return ans;
    }
    int countNumbersWithUniqueDigits(int n) {
       int ans=0;
       vector<bool>vis(10,0);
       for(int i=1;i<=n;i++){
        ans=ans+func(i,vis,i);
       }
       return ans+1;       //for handling the 0 case i.e. for n=0 the no existing is 1 so +1 is there
    }
};