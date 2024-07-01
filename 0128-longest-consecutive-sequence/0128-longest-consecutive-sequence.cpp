class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0)return 0;
        int longest =0;

        set<int>st;
       for(int i=0;i<n;i++){
        st.insert(nums[i]);
       }
       int cnt =1;
       for(auto i: st){
          if(st.find(i+1)!=st.end()){
            cnt++;
          }
          else if(cnt>longest){
            longest = cnt;
          }
       }
       return longest;
  
    }
};