class Solution {
public:
    int totalMoney(int n) {
    int weeks = n / 7;
    int days = n % 7;
    int total = 0;

  
    total += (weeks * (2 + weeks - 1) * 7) / 2; // Arithmetic progression sum for week starts
    total += 21 * weeks; // Because sum of 1..7 = 28, difference between weeks = 7

   
    int start = weeks + 1;
    for (int i = 0; i < days; i++) {
        total += start + i;
    }

    return total;
    }
};