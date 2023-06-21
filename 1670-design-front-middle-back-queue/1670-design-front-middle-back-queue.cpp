class FrontMiddleBackQueue {
public:
deque<int>dq1,dq2;
    FrontMiddleBackQueue() {
        
    }
    
    void balance()
    {
        if(dq1.size()-dq2.size()==0 || dq1.size()-dq2.size()==1)
        return;
        else if(dq1.size()>dq2.size()){
            int x=dq1.back();
            dq1.pop_back();
            dq2.push_front(x);
        }
        else{
            int x=dq2.front();
            dq2.pop_front();
            dq1.push_back(x);
        }
    }

    void pushFront(int val) {
        dq1.push_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        if(dq1.size()==dq2.size())
        dq1.push_back(val);
        else
        {
            int x=dq1.back();
            dq1.pop_back();
            dq1.push_back(val);
            dq2.push_front(x);
        }
    }
    
    void pushBack(int val) {
        dq2.push_back(val);
        balance();
    }
    
    int popFront() {
        int ans=-1;
        if(dq1.empty())
        return -1;
        
        else{
             ans=dq1.front();
            dq1.pop_front();
            balance();
        }
        return ans;
    }
    
    int popMiddle() {
        int ans=-1;
        if(dq1.empty() && dq2.empty())
        return -1;
        else{
            ans=dq1.back();
            dq1.pop_back();
            balance();
        }
        return ans;
    }
    
    int popBack() {
        int ans=-1;
        if(dq2.empty())
        {
            if(dq1.empty())
            {
            
               return -1; 
            }
            else{
                ans=dq1.back();
                dq1.pop_back();
                
            }
        }
        else{
            ans=dq2.back();
            dq2.pop_back();
        }
        balance();
        return ans;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */