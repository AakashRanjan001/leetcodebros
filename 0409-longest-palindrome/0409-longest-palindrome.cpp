class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char,int>mp;

        for(auto i:s){
            mp[i]++;
        }
        bool isOdd = false;
        int cnt =0;
        for(auto it:mp){
            
            if(it.second%2==0){
                cnt+=it.second;
            }
            else{
            
                cnt+=it.second-1;
                isOdd = true;
            }
        }
        return isOdd ? cnt+1 :cnt;

    }
};