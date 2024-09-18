class Solution {
public:
   static bool cmp(int a , int b){
      string s1 = to_string(a);
      string s2 = to_string(b);
        
        if(s1+s2 > s2+s1){
            return true;
        }
        else{
            return false;
        }
       
   }
     
    string largestNumber(vector<int>& nums) {
        
        // using of custom comparator we have to check after concatenation which string is forming larger
        int n = nums.size();
        sort(nums.begin(),nums.end(),cmp);

        // important edge case that i always miss
        // if all the numbers in astring is equal yo zero
        if(nums[0] == 0)return "0";

        string ans ="";
        for(int i=0;i<n;i++){
            ans+=to_string(nums[i]);
        }
        return ans;
    }
};