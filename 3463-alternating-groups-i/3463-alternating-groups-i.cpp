class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& s) {
        int len=s.size();
        int ans=0;
        for(int i=0;i<len;i++){
            if(s[i]==0 && s[(i+1)%len]==1 && s[(i+2)%len]==0){
                    ans++;
            }else if(s[i]==1 && s[(i+1)%len]==0 && s[(i+2)%len]==1){
                ans++;
            }
        }
        return ans;
    }
};
