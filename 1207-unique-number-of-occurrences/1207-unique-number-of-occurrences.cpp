class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(auto x:arr){
            freq[x]++;
        }
        unordered_set<int>s;
        for(auto x:freq){
            s.insert(x.second);
        }
        if(freq.size()==s.size()){
            return true;
        }
        return false;
    }
};