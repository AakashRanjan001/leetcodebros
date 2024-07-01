class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        //the three consecutive integers are x-1,x,x+1

        if(num%3!=0){
            return {};
        }
        return {num/3-1 , num/3 , num/3 +1};
    }
};