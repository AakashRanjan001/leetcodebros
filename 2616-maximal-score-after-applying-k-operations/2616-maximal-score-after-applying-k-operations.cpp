
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
         priority_queue<int> pq;
         long long sum = 0;

         for(int i = 0; i< nums.size(); i++)
         {
            pq.push(nums[i]);
         }

         while(k--)
         {
            double val = pq.top();
            sum += val;
            pq.pop(); 
            val = ceil(val/3);
            pq.push(val);

         }
         return sum;
    }
};