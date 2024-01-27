class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            int a = digits[i];
            digits[i]=(digits[i]+carry)%10;
            carry= (a+carry)/10;
            ans.push_back(digits[i]);
        }
        if(carry ==1){
            ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};