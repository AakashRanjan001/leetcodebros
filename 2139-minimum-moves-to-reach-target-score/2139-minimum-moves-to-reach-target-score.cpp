class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        
        long long oper =0;
        while(target>1){
             
             if(target % 2 ==0 && maxDoubles > 0){
                target = target/2;
            
                maxDoubles--;
                
             }
             else if(maxDoubles == 0 ){
                 oper+=(target-1);
                 break;
               
             }
             else{
                target = target -1;
              
             }
             oper++;
        }
        return oper;
      
    }
};