class Solution {
public:
    int numSteps(string s) {
        int ans =0;
        int carry =0;
        int n = s.size();

        for(int i=n-1;i>=1;i--){
            if((s[i]-'0'+carry)%2==1){
                //means it is an odd no. and we have to add 1 and after performing it becomes even and hence we do right shift
                ans+=2;
                carry =1;
            }else{
                ans+=1;
            }
    
        }
      return ans+carry;

    }
};