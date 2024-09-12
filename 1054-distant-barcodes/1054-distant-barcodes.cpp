class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int,int>mp;
        for(auto it: barcodes){
            mp[it]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(pq.size()>1){
            pair<int,int>p1=pq.top();
            pq.pop();
            pair<int,int>p2=pq.top();
            pq.pop();
            ans.push_back(p1.second);
            ans.push_back(p2.second);
            p1.first--;
            p2.first--;
            if(p1.first>0){
                pq.push(p1);
            }
            if(p2.first>0){
                pq.push(p2);
            }
        }
        if(pq.size()==1)  ans.push_back(pq.top().second);

        return ans;
    }
};