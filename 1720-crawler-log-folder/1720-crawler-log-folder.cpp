class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int n = logs.size();
        int cnt =0;
        for(int i=0;i<n;i++){
            if(logs[i]=="../"){
                if(cnt>0){
                    cnt--;
                }

            }
            else if(logs[i]=="./"){
                continue;      
            }
            else{
                cnt++;
            }
            
        }
        return cnt;
    }
};