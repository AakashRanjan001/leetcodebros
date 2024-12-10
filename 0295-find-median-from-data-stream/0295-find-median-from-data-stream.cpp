
class MedianFinder {
public:
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    MedianFinder() 
    { }
    
    void addNum(int num)   
    {   
        
        if(maxq.empty() || num < maxq.top())
            maxq.push(num);
        else
            minq.push(num);          
        

        if(abs((int)maxq.size() - (int)minq.size()) > 1 )
        {
            minq.push(maxq.top());
            maxq.pop();
        }
        else if(maxq.size() < minq.size())
        {
            maxq.push(minq.top());
            minq.pop();
        }
        
    }
    
    double findMedian() 
    { 
        if(minq.size() > maxq.size())
            return minq.top();
        if(maxq.size()> minq.size())
            return maxq.top();
        else
        {
            return (maxq.top() + minq.top())/2.0;
        }
        
    }

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */