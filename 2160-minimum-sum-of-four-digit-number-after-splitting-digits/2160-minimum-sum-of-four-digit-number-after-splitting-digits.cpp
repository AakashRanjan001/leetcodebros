
class Solution {
public:
    int minimumSum(int num) {
        int digit[4];
        int i;

        for(i = 0; i <4; i++)
        {
            digit[i] = num%10;
            num/=10;
        }
        sort(digit,digit+4);
        return (digit[0]*10+digit[2]) + (digit[1]*10+digit[3]);
    }
};