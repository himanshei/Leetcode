class MedianFinder {
public:
priority_queue<int>pq1;
priority_queue<int,vector<int>,greater<int>>pq2;
int len=0;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
       len++;
       if(len%2==1){
        pq2.push(num);
        pq1.push(pq2.top());
        pq2.pop();
       }
       else{
        pq1.push(num);
        pq2.push(pq1.top());
        pq1.pop();
       }
    }
    
    double findMedian() {
       if(len%2==1){
        return pq1.top();
       }else{
        double a =pq1.top(),b=pq2.top();
        double ans=a+b;
        ans=ans/2;
        return ans;
       }
    }
};   

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */