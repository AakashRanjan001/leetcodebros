class Solution {
public:
    bool isSetBit(int n){
   string temp = "";
  while(n!=0){
         int rem= n%2;
         temp.push_back(rem + '0');
         n = n/2;
      }
       
       reverse(temp.begin(),temp.end());
       for(auto i:temp){
          if( i == '0')return false;
        
       }
       temp.clear();
       return true;
    }
    int smallestNumber(int n) {
         for(int i=n;;i++){
              if(isSetBit(i)){
                 return i;
              }
              else{
                 continue;
              }
         }    
         return 0; 
    }
};