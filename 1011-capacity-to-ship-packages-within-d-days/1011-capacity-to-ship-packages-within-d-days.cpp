class Solution {
public:
bool func(int mid,int days,vector<int>weights){
     int n=weights.size();
     int cp=mid;
     int temp=0,ct=0;
     for(int j=0;j<n;j++){
     if(temp+weights[j]>cp){
        temp=0;
        ct++;
     }
        temp+=weights[j];
    }
    ct++;
    if(ct<=days) return 1;
    else return 0;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
      while(high-low>1){
        int mid=(high+low)/2;
        if(func(mid,days,weights)){
            high=mid;
        }
        else low=mid+1;
      }
      if(func(low,days,weights)) return low;
      else return high;
      return -1;
    }
  
};