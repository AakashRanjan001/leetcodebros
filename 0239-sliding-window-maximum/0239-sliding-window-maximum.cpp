class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // ye sliding window plus queue ka question hao 
         //brute force
        //  int maxi = INT_MIN; 
        //  vector<int>res;
        //  for(int i=0;i<=nums.size() - k;i++){
        //     maxi = INT_MIN;
        //     for(int j=i;j<i+k;j++){
        //           maxi = max(maxi,nums[j]);
        //     }
        //     res.push_back(maxi);
        //  }
        //  return res;

       //optimal is sliding and queue
       deque<int>q;
       int n = nums.size();
       int maxi = INT_MIN;
       int i=0;
       int j=0;
       vector<int>res;


       while(j<n){
          //calculation to find out the maxi 
            while( !q.empty() && q.back()<nums[j] ){
                 q.pop_back();
            }
            q.push_back(nums[j]);

            if(j-i+1 < k){
                 j++;
            }

            else if(j-i+1 == k){
                 //ans nikalo from calculationa and slide the window
                 res.push_back(q.front());
                 //slide 
                 if(nums[i] == q.front()){
                     q.pop_front();
                    
                 }
                  i++;
                  j++;
                   
            }
           
       }
       return res;


    }
};