class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
      
              set<int>st;
       vector<int>result;
       for(auto ele:nums1){
           for(auto it:nums2){
               if(ele==it){
                   st.insert(ele);
               }
           }
       }
       for(auto itr:st){
           result.push_back(itr);
       }
       return result;
        }
        
    
};