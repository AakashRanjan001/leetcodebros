#define MOD 1000000007

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        
        // int n = arr.size();
        // int cnt =0;
        // //generate all the subarrays and then find their sum which is odd
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         int sum =0;
        //         for(int k=i;k<=j;k++){
        //              sum+=arr[k];
        //         }
        //         if(sum%2!=0)cnt++;
        //     }
        // }
        // return cnt% MOD;

      //we can even use the concept of odd number and even number sum 
      // odd + even = odd
      // odd + odd = even
      // even + even = even 
    
       int n = arr.size();
       int sum =0;
       //odd and even are the count of the nunmber of prefux sums which are either odd or even
       int odd =0; 
       int even = 1; //as becuase an empty prefix sum is even 
       int count =0;
        
        for (int num : arr) {
            sum += num;
            if (sum % 2 == 0) {
                count = (count + odd) % MOD;
                even++;
            } else {
                count = (count + even) % MOD;
                odd++;
            }
        }
        return count;
    }
};