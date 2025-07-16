class Solution {
public:
    int maximumLength(vector<int>& nums) {
         int n = nums.size();
         //for the even case and odd case where % 2 == 0
         int evens =0 , odds = 0;
         int maxcnt = -1;
         for(int i=0;i<n;i++){
             if(nums[i]%2 ==0){
                 evens++;
             }
             else if(nums[i]%2 == 1){
                 odds++;
             }
         }
         maxcnt = max(evens,odds);

         //alternatong parity sequence 
         int altercnt = 1;
         int prevParity = nums[0]%2;
         for(int i=1;i<n;i++){
             if(nums[i]%2 !=prevParity){
                 // i can pick then this element
                 altercnt++;
                 prevParity = nums[i]%2;
             }

         }
         maxcnt = max(altercnt , maxcnt);
         return maxcnt;

    }
};