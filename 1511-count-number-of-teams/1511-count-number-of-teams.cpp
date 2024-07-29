class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        //extreme brute force
        int n = rating.size();
        int cnt =0;
        for(int i=0;i<n-2;i++){
            for(int j =i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if((rating[i]<rating[j] && rating[j]<rating[k]) || (rating[i]>rating[j] && rating[j]>rating[k])){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};