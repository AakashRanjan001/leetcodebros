class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         int n = nums1.size();
         vector<int>ans;
         for(int i=0;i<n;i++){
             int search = nums1[i];
             int index = -1;
             for(int j=0;j<nums2.size();j++){
                  if(nums2[j] == search){
                       index = j;
                        bool found = false;

                       for(int k=index+1;k<nums2.size();k++){
                            if(nums2[k] > nums2[index]){
                                 ans.push_back(nums2[k]);
                                 found = true;
                                 break;
                            }
                       }
                      if(!found) ans.push_back(-1);
                  }
             }
         }
         return ans;
    }
};