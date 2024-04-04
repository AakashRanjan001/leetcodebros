class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int ans=0, cnt=0;
        for(char c:s){
            if(c=='(')cnt++;
            else if(c==')')cnt--;
            ans=max(ans, cnt);
        }
        return ans;
    }
};
