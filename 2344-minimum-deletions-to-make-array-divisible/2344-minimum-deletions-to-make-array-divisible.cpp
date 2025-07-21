class Solution {
public:
    int gcd(int a, int b){
        // int val = 1;
        //  for(int i=1;i<=min(a,b);i++){
        //      if(a%i == 0 && b%i == 0){
        //          val = max(val,i);
        //      }
        //  }
        //  return val;

        while(a>0 && b>0){
             int temp = b;
              b = a%b;
              a = temp;
        }
        return a;
    }
    
    int minOperations(vector<int>& nums, vector<int>& d) {
         // smallest number in the nums se dimaag mei aata hai (gcd) jisse woh divide kare
           int n = nums.size();
           int g = d[0];
           for(int i=1;i<d.size();i++){
              g = gcd(d[i],g);
           }
           sort(nums.begin(),nums.end());
           int res = -1;
           for(int i=0;i<nums.size();i++){
               if(g%nums[i] == 0){
                 return i;
               }
           }
           return -1;
          
          
    }
};