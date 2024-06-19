class Solution {
public:
    bool check(vector<int>&nums,int m,int k,int days){
        int cnt = 0,i = 0,n = nums.size();
        while(i<n){
            int t = 0;
            while(i<n && t<k && nums[i]<=days){
                t += 1;
                i += 1;
                if(t==k){
                    cnt += 1;
                    t = 0;
                }
            }
            if(i<n && nums[i]>days)i+=1;
            if(cnt>=m)return 1;
        }
        return 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo = 1, hi = 1e9+1, mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(check(bloomDay,m,k,mid)){
                hi = mid;
            }
            else lo = mid+1;
        }
        if(check(bloomDay,m,k,lo))return lo;
        else if(check(bloomDay,m,k,hi))return hi;
        return -1;
    }
};
