class Solution {
public:
    int minimumLength(string s) {
        
        //hashamap ka  question hai 
        int n = s.size();
        if(n<3)return n;
        unordered_map<char,int>left,right;
        for(int i=0;i<n;i++){
            right[s[i]]++;
        }
        int length = n;
        for(int i=0;i<n;i++){
            right[s[i]]--;
            if(left[s[i]]>0 && right[s[i]]>0){
                 length-=2;//agar left ya right side mei same aa gya tab length kam hoga 
                 left[s[i]]--;
            }
            else{
                //pehli baar koi character aaya hai
                left[s[i]]++; 
            }
        }
        return length;
    }
};