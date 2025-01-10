class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        //maximum frequencey wali unordered_map ban gya 
         unordered_map<char,int>freq;
         for(auto i:words2){
          unordered_map<char,int>temp;
            for(auto ch:i){
              temp[ch]++;
            }
            for(auto it:temp){
                freq[it.first] = max(freq[it.first],it.second);
            }
         }
     vector<string>ans;
     unordered_map<char,int>mp1;
     for(auto i:words1){
        mp1.clear();// YAHA MAI GALTI KIYA !!
        for(auto ch:i){
            mp1[ch]++;
        }
      
            bool flag = true;
            for(auto it = freq.begin();it!=freq.end();it++){
                if(mp1[it->first]<it->second){
                    flag = false;
                    break;
                }
            }
            // matlab string mil gya 
            if(flag == true){
                ans.push_back(i);
            }
     }
     return ans;
   
    }
};