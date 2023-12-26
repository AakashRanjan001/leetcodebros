class Solution {
public:
    int mySqrt(int x) {
        int s =0;
        int e = x;
    
        
        
        long long mid = s + (e-s)/2;
        for(;s<=e;){
            if(mid*mid==x){
                return mid;
            }
            else if(mid*mid<x){
                
                s = mid +1;
            }
            else{
                e = mid -1;
            }
            mid = s + (e-s)/2;        
        
    
        }
        return e;
    }
    
};