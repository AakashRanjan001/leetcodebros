class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //  int n = nums1.size();  // this is the brute force 
        //  vector<int>ans;
        //  for(int i=0;i<n;i++){
        //      int search = nums1[i];
        //      int index = -1;
        //      for(int j=0;j<nums2.size();j++){
        //           if(nums2[j] == search){
        //                index = j;
        //                 bool found = false;

        //                for(int k=index+1;k<nums2.size();k++){
        //                     if(nums2[k] > nums2[index]){
        //                          ans.push_back(nums2[k]);
        //                          found = true;
        //                          break;
        //                     }
        //                }
        //               if(!found) ans.push_back(-1);
        //           }
        //      }
        //  }
        //  return ans;

          int n = nums2.size();
          unordered_map<int,int>mp; // element ---> next greater
          stack<int>st;
          for(int i=n-1;i>=0;i--){
               //jab chota hai element right side me 
               while(!st.empty() && st.top()<=nums2[i]){
                   st.pop();
               }
               if(st.empty())mp[nums2[i]] = -1;
               else{
                  mp[nums2[i]] = st.top();
               }
               st.push(nums2[i]);
          }
          vector<int>ans;
          for(int i=0;i<nums1.size();i++){
              if(mp.find(nums1[i])!=mp.end()){
                  ans.push_back(mp[nums1[i]]);
              }
          }
return ans;
        
    }
};