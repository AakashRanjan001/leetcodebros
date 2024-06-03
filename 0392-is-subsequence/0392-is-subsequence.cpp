class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j= 0;

        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                j++;
                i++;
            }
            else{
                j++;
            }
        }
        return (i == s.size());//agar saare char milte toh hi i pura lastr tak pahuchta thats why we are using thisito return
    }
};