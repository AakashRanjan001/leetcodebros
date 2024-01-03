class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        int m = g.size();
        int n = s .size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int count =0;
        int i =0,j=0;
        while(i<m && j<n){
            if(g[i]<=s[j]){
                i++;
                j++;
                count++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};