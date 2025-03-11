// class Solution {
// public:
//     bool isPresentABC(string &s, int start, int end){
         
//          bool HasA = false,HasB = false, HasC = false;
//          for(int i=start;i<=end;i++){
//              if(s[i] == 'a')HasA = true;
//              if(s[i] == 'b')HasB = true;
//              if(s[i] == 'c')HasC = true;
//          }
//          return HasA && HasB && HasC;
       
//     }
//     int numberOfSubstrings(string s) {
        
//         //brute force coming to my mind 
//         int n = s.size();
//         int cnt =0;
//         for(int i=0;i<n;i++){
//              for(int j=i;j<n;j++){
//                   if(isPresentABC(s,i,j) == true){
//                     // cnt+=(n-j);
//                     // break;
//                       cnt++; 
//                   }
//              }
//         }
//         return cnt;
//     }
// };
class Solution {
public:
    int numberOfSubstrings(string s) {
        
        //sliding window appraoch that is variable sie sliding window 
        vector<int>hash(3,0);
        int n = s.size();
        int cnt =0;
        int i=0;
        int j=0;

        while(j<n){
            //calculation 
            hash[s[j] -'a']++;
            
            while(hash[0]>0 && hash[1]>0 && hash[2]>0){
                //matlab valid substring mil gya 
                cnt+=(n-j);
                //shrink the window
                hash[s[i]-'a']--;
                i++;

            }
            j++;

        }
        return cnt;
    }
};