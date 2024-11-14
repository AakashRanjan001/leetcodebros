class Solution {
public:
    int minimizedMaximum(int n, vector<int>& a) {
        int m = a.size();
        int l=1,r=*max_element(a.begin(),a.end());
        int ans = -1;
        auto check = [&](int mid)->bool{
            //cout<<"mid: "<<mid<<endl;
            int storeCnt = n;
            for(int i=0;i<m;i++){
                int ctr = a[i]/mid;
                //cout<<storeCnt<<" "<<ctr<<endl;
                if(storeCnt >= ctr){
                    storeCnt -= ctr;
                }
                else return 0;
                if(a[i]%mid!=0){
                    if(storeCnt > 0)
                    storeCnt -= 1;
                    else return 0;
                }
            }
            //cout<<"storeCnt: "<<storeCnt<<endl;
            //cout<<endl;
            return 1;
            //return storeCnt<=0;
        };
        while(l<=r){
            int mid = (l+r)>>1;
            if(check(mid)){
                ans = mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};

