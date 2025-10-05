class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //  int n = nums.size();
        //  vector<int>ans;
        //  for(int i=0;i<n;i++){
        //     int maxi = INT_MIN;
        //      for(int j=i;j<n;j++){
        //          maxi = max(maxi,nums[j]);

        //          if(j-i+1 == k){
        //              ans.push_back(maxi);
        //              break;
        //          }
        //      }
        //  }
        //  return ans;


        // by the use of deque but why we are using deque i have to understand
       int n = nums.size();
       deque<int>dq;
       vector<int>res;

       for(int i=0;i<n;i++){
          //step 1: jo bhi i-k se kam ke indexes hai deque mei usko valid window mei consider nhui karenge

          while(!dq.empty() && dq.front()<=i-k){
              dq.pop_front();
          }

          // step 2: agar nums[i] bada hai toh jo chote elemets hai usko remove karte chalo 
           while(!dq.empty() && nums[i] > nums[dq.back()]){
              dq.pop_back();
           }

           // step 3: deque mei answer daalo 
        dq.push_back(i);
           // step 4: res mei answer store karo har ek window ka 
           if(i>=k-1){ // agar valid window mila hai tab hi ye karna hai 
               res.push_back(nums[dq.front()]);
           }
         
       }
       return res;
    }
};