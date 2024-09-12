class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        set<char>st;
       for(int i=0;i<allowed.size();i++){
        st.insert(allowed[i]);
       }
       
        int cnt =0;
       
        for(int i=0;i<words.size();i++){
              string temp = words[i];
               bool flag = true;
               for(int j=0;j<temp.size();j++){
                   if(st.find(temp[j])==st.end()){
                    flag = false;
                     break;
                   }
               }
             
             if(flag){
                cnt++;
             }
        }
        return cnt;
    }
};