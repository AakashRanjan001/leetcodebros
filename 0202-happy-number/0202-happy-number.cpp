class Solution {
public:
    bool isHappy(int n) {
        if(n != 1 && n <= 9 && n != 7) {
            return false;
        }
        while(n != 1 && n != 4) { 
            
            int sum = 0;
            while(n > 0) {
                int num = n % 10;
                sum += num * num;
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};
