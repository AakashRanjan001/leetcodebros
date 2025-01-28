class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int i=0;
        int j=0;
        int mini = INT_MAX;
        int oper =0;

        while(j<n){
             //calculation 
             if(blocks[j] == 'W'){
                 oper++;
                 
             } 

             if(j-i+1<k){
                j++;
             }
             else if(j-i+1 == k){
                 mini= min(mini , oper);
                 if(blocks[i] == 'W'){
                     oper--;
                 }
                 i++;
                 j++;
             }

        }
        return mini;

    }
};