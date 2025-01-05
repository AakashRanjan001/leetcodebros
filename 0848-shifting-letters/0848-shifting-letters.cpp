class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        // for(int i=0;i<shifts.size();i++){ 
        //     int shift = shifts[i];
        //     for(int j=0;j<=i;j++){
        //          s[j] = (s[j] -'a' + shift)%26 + 'a';
        //     }
        // }
        // return s;

        // BRUTE FORCE --------->

        // after perofrming the opeartion it got to know it is forming a prefix sum for ut 
        int n = shifts.size();
        int prefix_sum =0;
        for(int i=n-1;i>=0;i--){
             prefix_sum+=shifts[i];

             s[i] = (s[i] - 'a' + prefix_sum) % 26 + 'a';
         }

        return s;
    }
};