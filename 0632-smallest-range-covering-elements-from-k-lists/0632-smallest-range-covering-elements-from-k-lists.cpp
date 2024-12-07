class node{
    public:
    int data;
    int row;
    int col;

    node(int val, int r , int c){
        data = val;
        row = r;
        col = c;
    }

};

class compare{
      public:
      bool operator()(node* a , node* b){
        return a->data > b->data;
      }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<node* ,vector<node*>,compare>minheap;

        // abb minheap mei first k elements ko push karna hai
        int k = nums.size();
       
        for(int i=0;i<k;i++){
           int element = nums[i][0];
           mini = min(element, mini);
           maxi = max(element,maxi);
           minheap.push(new node(nums[i][0], i , 0 ));
           
        }
        int ansStart = mini;
        int ansEnd = maxi;

        while(!minheap.empty()){
             node* top = minheap.top();
             int topelement = top->data;
             int toprow = top->row;
             int topcol = top->col;

             minheap.pop();

             // now before further adding aother element we have to update mini
             mini = topelement;// MINI UPDATED
             // mini update hui hai matlab range update hui hai 
             // check karna chahiye abhi jo mini update hui hai usse range kuch update hui hai 

             int currRange = maxi-mini;
             int ansRange = ansEnd - ansStart;
             if(currRange < ansRange){
                   ansStart = mini;
                   ansEnd = maxi;
             }

        // abb jo value pop lari hai toh check karo kya uske aage koi value exist karti hai ki nhi 
         if(topcol +1 < nums[toprow].size()){
            // this was missed apon max ki value ko update nhi kiye the anfter insertion
            maxi = max(nums[toprow][topcol+1],maxi);
            minheap.push(new node(nums[toprow][topcol+1] , toprow , topcol+1));

         }
         else{
            // maanlo aage element nhi hota 
            break;
         }
      
        }
vector<int>ans;
ans.push_back(ansStart);
ans.push_back(ansEnd);
        return ans;
        

    }
};