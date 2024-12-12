class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        //jab bhi maximum ya minimum nikalna hai then we should always use priority queueu
        priority_queue<int>pq;
        int n = gifts.size();

        for(int i=0;i<n;i++){
            pq.push(gifts[i]);
        }
        while(k--){
             int element = pq.top();
             pq.pop();

             element = floor(sqrt(element)); 
             pq.push(element);
        }  
      vector<int>ans;
      while(!pq.empty()){
         ans.push_back(pq.top());
         pq.pop();
      }
      long long sum =0;
      for(int i=0;i<ans.size();i++){
        sum+=ans[i];
      }
      return sum;
     

    }
};