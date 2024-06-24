class Solution {
public:
    int minKBitFlips(vector<int>& a, int k) {
        int n=a.size(), f=1, ans=0;
        vector<int> prf(n+9);
        for (int i=0; i<n; i++) {
            if (prf[i]) f^=1;
            if (a[i]) {
                if (!f) {
                    if (i-1+k<n) {
                        ans++;
                        prf[i+k]++;
                        f^=1;
                    } else return -1;
                }
            } else {
                if (f) {
                    if (i-1+k<n) {
                        ans++;
                        prf[i+k]++;
                        f^=1;
                    } else return -1;
                }
                a[i]=1;
            }
        }
        return ans;
    }
};
