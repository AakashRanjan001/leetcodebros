class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        colors.insert(colors.end(),colors.begin(),colors.end());
        int l=0,r=0,ans=0;
        while(l<n){
            if(r-l+1==k){
                l++;
                ans++;
            }
            if(colors[r]==colors[r+1]) l=r+1;
            r++;
        }
        return ans;
    }
};
