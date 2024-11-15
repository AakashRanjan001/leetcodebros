
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int start{ 0 }, end{ static_cast<int>(arr.size() - 1) };
        while (start < end && arr[start] <= arr[start + 1]) ++start;
        if (start == end) return 0;
        while (end >= 1 && arr[end] >= arr[end - 1]) --end;

        int minLen{ static_cast<int>(end) };
        for (int i{ 0 }; i <= start; ++i) {
            auto lb = std::lower_bound(arr.begin() + end, arr.end(), arr[i]);
            int c{ static_cast<int>(lb - arr.begin()) };
            minLen = std::min(minLen, c - i - 1);
        }

        return minLen;
    }
};
