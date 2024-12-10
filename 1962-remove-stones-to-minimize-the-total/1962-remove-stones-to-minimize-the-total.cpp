class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int>pq;
        
        for(int i=0;i<n;i++){
            pq.push(piles[i]);
        }
       
        while(k--){ // yahja mei galti hua tha dhyan rakhna 
             int topElement = pq.top();
             pq.pop(); // firt removing the top elment 
             topElement -= topElement/2 ; // divide the top elment and subtracted it 
           pq.push(topElement);
          
        }
       int sum =0;
       while(!pq.empty()){
          sum+=pq.top();
          pq.pop();
       }
       return sum;
    }
};