class Solution {
public:
    bool isVowel(char c){
         unordered_set<char>st = {'a', 'e', 'i', 'o', 'u' , 'A', 'E', 'I', 'O', 'U'};
         for(auto it:st){
             if(st.find(it)!=st.end()){
                 return true;
             }
         }
         return false;
    }
    bool doesAliceWin(string s) {
         
         set<char>st={'a','e','i','o','u'};
         int count=0;
         for(auto &it : s){
            if(st.count(it)) count++;
         }
         if(count==0) return 0;
         return 1;

    }
};