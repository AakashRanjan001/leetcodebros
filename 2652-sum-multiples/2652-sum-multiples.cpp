class Solution {
public:
    int sumOfMultiples(int n) {
        
        vector<int>ans(n);
        for(int i=1;i<=n;i++){
        if(i%3==0 ||i%5==0 || i%7==0){
            ans.push_back(i);
        }
        }
        int sum =0;
        for(int i=0;i<ans.size();i++){
            sum = sum + ans[i];
        }
        return sum;
    }
};