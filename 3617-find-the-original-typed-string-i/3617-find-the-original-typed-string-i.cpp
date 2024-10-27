class Solution {
public:
    int possibleStringCount(string word) {
        int ans =0;
        int n= word.size();
        if(word.size() == 1)return 1;
        for(int i=0;i<n-1;i++){
            if(word[i] == word[i+1]){
                ans++;
            }
        }
        return ans+1;
    }
};