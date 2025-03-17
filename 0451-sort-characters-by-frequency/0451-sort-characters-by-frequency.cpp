class Solution {
public:
    string frequencySort(string s) {
        
    //     map<char,int>mp;
    //     for(auto i:s){
    //         mp[i]++;
    //     }
    //    string ans ="";
    //     for(auto it:mp){
    //         if(it.second>1){
    //             while(it.second>1){
    //                  ans+=it.first;
    //                  it.second--;
    //             }
    //         }
    //         ans+=it.first;
    //     }
    //     return ans;
 // the method which  i applied above is wrong becaus e
 // the storing of map is based on the ASCII values in the lexicographical order 
 //your code processes characters in the order they appear in the map, which is sorted by character values (lexicographically) instead of frequency.


        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        vector<pair<int, char>> freq;
        for (auto& it : mp) {
            freq.push_back({it.second, it.first});
        }

        sort(freq.rbegin(), freq.rend()); // Sort in descending order of frequency

        string ans = "";
        for (auto& it : freq) {
            for (int i = 0; i < it.first; i++) { // Add character 'it.first' times
                ans += it.second;
            }
        }

        return ans;
    }
};