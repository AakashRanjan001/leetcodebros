class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0;
        int j=0;
        int curr =0;
        int ans =0;

        while(j<t.size()){
            curr+= abs(t[j]-s[j]);
            j++;

            while(i<j && curr>maxCost){
                curr-= abs(t[i]-s[i]);
                i++;
            }
            if(curr<=maxCost){
            ans = max(ans,j-i);
        }
        }
        

          return ans;


    }
};