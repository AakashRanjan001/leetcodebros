// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n = nums.size();
//         int maxlen = 1;
//         if(n == 0)return 0;

//         unordered_set<int>s(nums.begin(),nums.end());
//         auto prev = s.begin();
//         auto it = next(s.begin());
//         int cnt = 1;

//         while(it!=s.end()){
//              if(*prev +1 == *it){
//                  cnt++;
//              }
//              else{
//                  cnt =1;
//              }
//              maxlen = max(maxlen,cnt);
//              prev = it;
//              it++;
//         }
//         return maxlen;
//     }
// };

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        set<int> s(nums.begin(), nums.end());

        int longest = 1, cnt = 1;
        auto prev = s.begin();
        auto it = next(s.begin());

        while(it != s.end()) {
            if(*it == *prev + 1) {
                cnt++;
            } else {
                cnt = 1;
            }
            longest = max(longest, cnt);
            prev = it;
            ++it;
        }

        return longest;
    }
};
