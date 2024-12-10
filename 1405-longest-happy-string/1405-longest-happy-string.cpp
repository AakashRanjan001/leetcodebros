class node{
    public:
     char data;
     int  count;

     node(char d , int c){
          data = d;
          count =c;
     }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->count < b->count;
    }

};
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<node*,vector<node*>,compare>MaxHeap;
        // maxheap mei abb insert karna hai

        if(a!=0){
            node* temp = new node('a',a);
            MaxHeap.push(temp);
        }
        if(b!=0){
            node* temp = new node('b',b);
            MaxHeap.push(temp);
        }
        if(c!=0){
            node* temp = new node('c',c);
            MaxHeap.push(temp);
        }
        string ans = "";
      // taaki 2 elements saath mei nikale isi kaaran , toh last mei 2 elements last mei rahe 
        while(MaxHeap.size()>1){
            node* first = MaxHeap.top();
            MaxHeap.pop();
            node* second = MaxHeap.top();
            MaxHeap.pop();
           

           if(first->count>=2){ // ek baar mei 2 ko insert kar sakte hai at most
              ans+=first->data; 
              ans+=first->data;

              first->count-=2;
           }
           else{
              // matlab 1 hi count hai toh ek hi insert karenge
              ans+=first->data;
              first->count--;
           }

           // Now similarly for the second element we have to perform this
           if(second->count>=2 && second->count >=first->count){ // ek baar mei 2 ko insert kar sakte hai at most
              ans+=second->data; 
              ans+=second->data;

              second->count-=2;
           }
           else{
              // matlab 1 hi count hai toh ek hi insert karenge
              ans+=second->data;
              second->count--;
           }
                // abb ek baar kar diye hai toh abb usko insert karenge wpas heap mei
        if(first->count !=0){
            MaxHeap.push(first);
        }
        if(second->count !=0){
            MaxHeap.push(second);
        }
     }

        if(MaxHeap.size() == 1){
            node* temp = MaxHeap.top();
            MaxHeap.pop();
            
              if(temp->count>=2){ // ek baar mei 2 ko insert kar sakte hai at most
              ans+=temp->data; 
              ans+=temp->data;

              temp->count-=2;
           }
           else{
              // matlab 1 hi count hai toh ek hi insert karenge
              ans+=temp->data;
              temp->count--;
           }

        }
       return ans;
      
    }
};