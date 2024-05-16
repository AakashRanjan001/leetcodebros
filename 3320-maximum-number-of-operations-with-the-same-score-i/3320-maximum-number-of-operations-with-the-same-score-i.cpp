class Solution {
public:
    int maxOperations(vector<int>& a) {
        int n=a.size();
        int cnt=0;
        int sum=a[0]+a[1];
        for(int i=0;i<n;i+=2){
            if(i+1<n && a[i]+a[i+1]==sum)    cnt++;
            else    break;
        }
        return cnt;
    }
};
