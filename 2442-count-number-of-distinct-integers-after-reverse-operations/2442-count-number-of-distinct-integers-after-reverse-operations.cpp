
class Solution {
public:
    int reverse(int n){
        int rem = 0;
        while(n>0){
            rem = rem*10;
            rem = rem + (n%10);
            n= n /10;      
        }
        return rem;
    }

    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int rev  = reverse(nums[i]);
            nums.push_back(rev);
        }
        unordered_set<int> s;
        for(int i =0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        return s.size();
    }
};