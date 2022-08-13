class MedianFinder {
public:
    priority_queue < int > q1;
    priority_queue < int, vector < int > , greater < int >> q2;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(q1.empty() || q1.top() > num){
            q1.push(num);
        }
        else q2.push(num);
        
        if(q1.size() > q2.size() + 1){
            q2.push(q1.top());
            q1.pop();
        }
        else if(q2.size() > q1.size() + 1){
            q1.push(q2.top());
            q2.pop();
        }
    }
    
    double findMedian() {
        int lsize = q1.size();
        int rsize = q2.size();
        if(lsize > rsize)  //Return top of maxheap for odd no of elements
            return double(q1.top());
        
        else if(lsize < rsize)
                        return double(q2.top());

        else    //Else return avg of top of maxheap and minheap
            return (double(q1.top())+double(q2.top()))/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */