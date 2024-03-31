class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int temp = x;
        int sum=0;
        while(temp>=1){
            sum+=temp%10;
            temp=temp/10;
        }
        if(x%sum==0){
            return sum;
        }
        return -1;
    }
};
