class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
     sort(nums1.rbegin(),nums1.rend());
     sort(nums2.rbegin(),nums2.rend());

     return nums2[0]-nums1[0];
     


    

    }
};