class MinStack {
public:
   vector<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){ //stack is empty
        //so jo bhi val hai usko bass push kar denege
         pair<int,int>p = {p.first = val , p.second = val};
         st.push_back(p);
        }

        else{ //jab stack is not empty
        pair<int,int>p;
        p.first = val;
        p.second = min(val , st.back().second);
        st.push_back(p);

        }
    }
    
    void pop() {
        st.pop_back();
        
    }
    
    int top() {
        return st[st.size()-1].first;
        
    }
    
    int getMin() {
        return st[st.size()-1].second;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */