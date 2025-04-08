
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        int oper =0;
        int size_left =0;
        for(int i=n-1;i>=0;i--){
             if(st.find(nums[i]) == st.end()){
                 st.insert(nums[i]);
             }
            else{
                //agar duplicate mila toh
                 size_left = n-st.size();    
                break;
            }
        }
      
     oper =(size_left + 2)/3;
        return oper;
    }
};