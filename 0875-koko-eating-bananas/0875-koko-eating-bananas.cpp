class Solution {
public:
    bool func(int mid,vector<int>&piles,int h){
        int time=0;
        for(int i=0;i<piles.size();i++){
           if(piles[i]%mid==0){
             time=time+piles[i]/mid;
           }
           else {
            time=time+piles[i]/mid+1;
           }
        }
        if(time<=h)return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(high-low>1){
            int mid=(high+low)/2;
            if(func(mid,piles,h)) high=mid;
            else low=mid+1;   
        }
        if(func(low,piles,h)) return low;
        return high;
    }
};