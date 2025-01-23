class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window quwstion 
        int n = s.size();
        int i=0;
        int j=0;
        int maxi = 0;
        map<char,int>mp;

        while(j<n){
            mp[s[j]]++;

            while(mp[s[j]]>1){ // jab tak apon ko frequency greater than 1 mil rha tab tak shrink karna hia window thi khai
                 mp[s[i]]--;
                 i++;
            }
            maxi = max(maxi , j-i+1);
            j++;

        }
        return maxi;
    }
};