class Solution {
public:
    int firstUniqChar(string s) {
       int n = s.size();
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(mpp[s[i]]==1){
                return i;
                break;
            }
        }
        return -1;
    }
};