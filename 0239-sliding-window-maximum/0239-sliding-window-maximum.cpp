class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         int n = nums.size();
         deque<int>dq;
         vector<int>res;
         int i=0,j=0;
         while(j<n){
             //calculation 
              while(!dq.empty() && dq.back()<nums[j]){
                  dq.pop_back();
              }
              dq.push_back(nums[j]);

              if(j-i+1<k)j++;
              else if(j-i+1 == k){
                 res.push_back(dq.front());

                 if(nums[i] == dq.front()){
                     dq.pop_front();
            
                 }
              i++;
              j++;
              }
          
         }
         return res;

    }
};