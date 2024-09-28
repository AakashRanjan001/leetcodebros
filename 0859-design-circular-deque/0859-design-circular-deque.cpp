
class Node{
    public:
        int val;
        Node* next; 
        Node* prev;

        Node(int val = 0){
            this->val = val;
            next = NULL;
            prev = NULL;
        }
};

class MyCircularDeque {
public:
    Node* dummy = NULL;
    int size;
    int max;
    MyCircularDeque(int k) {
        dummy = new Node(-1);
        size = 0;
        max = k;

        dummy -> next = dummy;
        dummy -> prev = dummy;
    }
    
    bool insertFront(int value) {
        if(size == max) return false;

        Node* newNode = new Node(value);
        dummy -> next -> prev = newNode;
        newNode -> next = dummy -> next;
        newNode -> prev = dummy;
        dummy -> next = newNode;
        size ++;

        return true;
    }
    
    bool insertLast(int value) {
        if(size == max) return false;

        Node* newNode = new Node(value);
        dummy -> prev -> next = newNode;
        newNode -> prev = dummy -> prev;
        newNode -> next = dummy;
        dummy -> prev = newNode;
        size ++;

        return true;
    }
    
    bool deleteFront() {
        if(size == 0) return false;

        Node* temp = dummy -> next;
        dummy -> next = temp -> next;
        dummy -> next -> prev = dummy;

        delete temp;
        size --;

        return true;
    }
    
    bool deleteLast() {
        if(size == 0) return false;

        Node* temp = dummy -> prev;
        dummy -> prev = temp -> prev;
        temp -> prev -> next = dummy;

        delete temp;
        size --;

        return true;
    }
    
    int getFront() {
        return size > 0 ? dummy -> next -> val : -1;
    }
    
    int getRear() {
        return size > 0 ? dummy -> prev -> val : -1;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == max;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */