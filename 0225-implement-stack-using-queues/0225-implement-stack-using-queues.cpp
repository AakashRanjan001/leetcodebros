class MyStack {
public:
    queue<int> q1, q2;

    MyStack() {}

    void push(int x) {
        q2.push(x);

        
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
    }

    int pop() {
        int res = q1.front();
        q1.pop();
        return res;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
