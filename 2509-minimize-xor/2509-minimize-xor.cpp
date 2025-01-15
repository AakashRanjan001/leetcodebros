class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // Count the number of 1-bits in num2
        int countBits = __builtin_popcount(num2);
        
        // Start with num1 and modify it to match the bit count of num2
        int result = 0;
        
        // Set bits in the result starting from the most significant bit of num1
        for (int i = 31; i >= 0 && countBits > 0; --i) {
            if (num1 & (1 << i)) {
                result |= (1 << i);
                --countBits;
            }
        }
        
        // If more bits need to be set, set them starting from the least significant bit
        for (int i = 0; i <= 31 && countBits > 0; ++i) {
            if (!(result & (1 << i))) {
                result |= (1 << i);
                --countBits;
            }
        }
        
        return result;
    }
};
