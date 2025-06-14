class Solution {
public:
    int minMaxDifference(int num) {
         string t = to_string(num);
         char first;
         for(int i=0;i<t.size();i++){
             if(t[i]<'9'){
                 first = t[i];
                 break;
             }
         }
         for(int i=0;i<t.size();i++){
             if(t[i] == first){
                 t[i] = '9';
             }
         }
        
        string s = to_string(num);
         char f;
         for(int i=0;i<s.size();i++){
             if(s[i]>'0'){
                 f = s[i];
                 break;
             }
         }
         for(int i=0;i<s.size();i++){
             if(s[i] == f){
                 s[i] = '0';
             }
         }
         return stoi(t) - stoi(s);
    }
};