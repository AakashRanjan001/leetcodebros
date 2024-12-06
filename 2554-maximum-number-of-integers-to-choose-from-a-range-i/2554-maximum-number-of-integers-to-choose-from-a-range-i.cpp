class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        int n1 = banned.size();
        set<int>st;
        for(int i=0;i<n1;i++){
            st.insert(banned[i]);
        }
        vector<int>temp;
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()){
                   temp.push_back(i);
            }
            else{
                continue;
            }
        }

        int cnt=0;
        int sum =0;
        for(int i=0;i<temp.size();i++){
            sum+=temp[i];
             
             if(sum<=maxSum){
                cnt++;
             }           
        }
        return cnt;
    }
};