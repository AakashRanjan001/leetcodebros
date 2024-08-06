
class Solution {
public:
    int minimumPushes(std::string word) {
        // Initialize frequency array for each letter
        std::vector<int> letterCount(26, 0);

        // Count the frequency of each letter in the word
        for (char ch : word) {
            letterCount[ch - 'a']++;
        }

        // Sort frequencies in descending order
        std::sort(letterCount.begin(), letterCount.end(), std::greater<int>());

        long long pushes = 0;
        long long cnt = 0;

        // Calculate minimum pushes needed
        for (int i = 0; i < letterCount.size(); i++) {
            cnt++;
            if (letterCount[i] == 0) break;  // No need to count further if frequency is zero

            if (cnt <= 8) {
                pushes += 1 * letterCount[i];
            } else if (cnt <= 16) {
                pushes += 2 * letterCount[i];
            } else if (cnt <= 24) {
                pushes += 3 * letterCount[i];
            } else {
                pushes += 4 * letterCount[i];
            }
        }
        return pushes;
    }
};