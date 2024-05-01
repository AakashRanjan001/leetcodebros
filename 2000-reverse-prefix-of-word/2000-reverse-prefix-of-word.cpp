class Solution {
public:
    string reversePrefix(string word, char ch) {
        
     int left =0;
     int n = word.size();

     for(int right =0;right<n;right++){
        if(word[right]==ch){
        while(left<=right){
            swap(word[left],word[right]);
            left++;
            right--;
          }
          return word;
     }
     
     }
     return word;  //if we could not find ch then
    }
};