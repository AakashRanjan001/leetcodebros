
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int left = -1, right = -1;

        // Iterate through the string to find the best swap positions
        for (int i = 0; i < s.size(); i++) {
            for (int j = s.size()-1; j >i; j--) {
                // Check if we can swap to make a larger number
                if (s[i] < s[j] && (right == -1 || s[j] > s[right])) {
                    left = i;
                    right = j;
                }
            }
            // Exit early if we found a potential swap
            if (left != -1 && right != -1) break;
        }

        // If a valid swap was found, perform it
        if (left != -1 && right != -1) {
            swap(s[left], s[right]);
        }

        return stoi(s); // Return the new maximum number
    }
};