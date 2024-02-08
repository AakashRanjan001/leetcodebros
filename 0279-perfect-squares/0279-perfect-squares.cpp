class Solution {
public:
    int numSquares(int n) {
        
vector<int>ans;
int x = 1;
while(x*x<=n){
    ans.push_back(x*x);
    x++;
}

for(int i=0;i<ans.size();i++){
    if(ans[i]==n){         //agar mera n hi perfect sqaure hua toh ek hi baar mei ho jayega
        return 1;
    }
}
  for (int i = 0; i < ans.size(); i++) {
            for (int j = i; j < ans.size(); j++) {
                if (ans[i] + ans[j] == n) {
                    return 2;
                }
            }
        }

            for (int i = 0; i < ans.size(); i++) {
            for (int j = i; j < ans.size(); j++) {
                for (int k = j; k < ans.size(); k++) {
                    if (ans[i] + ans[j] + ans[k] == n) {
                        return 3;
                    }
                }
            }
        }
        
        return 4;
    }
};
