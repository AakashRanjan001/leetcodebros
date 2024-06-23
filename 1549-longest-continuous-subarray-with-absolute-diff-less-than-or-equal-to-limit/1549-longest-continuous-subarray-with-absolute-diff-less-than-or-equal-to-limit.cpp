
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> st;
        int end = 0;
        int start = 0;
        int window = 0;
        while(end < nums.size()){
            st.insert(nums[end]);
            while(*st.rbegin() - *st.begin() > limit){
                st.erase(st.find(nums[start]));
                start++;
            }
            window = max(window, end - start + 1);
            end++;
        }
        return window;
    }
};