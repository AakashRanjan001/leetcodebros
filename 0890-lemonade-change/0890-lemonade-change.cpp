
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
           int n = bills.size();
           int cnt_5 =0;
           int cnt_10 = 0;
           int cnt_20 =0;

           for(int i=0;i<n;i++){
            if(bills[i]==5){
                cnt_5++;
            }
            else if(bills[i]==10){
                    if(cnt_5!=0){
                        cnt_10++;
                        cnt_5--;
                    }
                    else{
                        return false;
                    }
            }
            else{
                if(bills[i]==20){
                    if(cnt_5!=0 && cnt_10!=0){
                        cnt_5--;
                        cnt_10--;
                        cnt_20++;
                    }
                    else if(cnt_5>=3){
                          cnt_5-=3;
                    }
                    else{
                        return false;
                    }
                }
            }
            

           } 
           return true;
    }
};