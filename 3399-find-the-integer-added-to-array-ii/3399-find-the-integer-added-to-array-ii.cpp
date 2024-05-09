class Solution {
public:
    bool check(vector<int>&nums1,vector<int> &nums2,int index)
    {
        int j = 0,i= index,diff = -nums1[i]+nums2[0];
        while(j<nums2.size() && i<nums1.size())
        {
            if(-nums1[i]+nums2[j]==diff)
            j++;
            i++;
        }
        return j==nums2.size();
    }

    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int ans = INT_MAX;

        for(int i=0;i< nums1.size();i++)
        {
            int diff = -nums1[i]+nums2[0];
            if(check(nums1,nums2,i))
            ans = min(ans,diff);
        }
        return ans;
    }
};
