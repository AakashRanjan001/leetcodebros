class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // Check for valid horizontal or vertical cuts
        return canPartition(rectangles, 0, 0, 2) || canPartition(rectangles, 1, 1, 3);
    }

private:
    bool canPartition(std::vector<std::vector<int>>& rectangles, int axis, int startIndex, int endIndex) {
        // Sort rectangles based on the specified axis (either x or y)
        std::sort(rectangles.begin(), rectangles.end(), [&](const std::vector<int>& a, const std::vector<int>& b) {
            return a[axis] < b[axis];
        });
        int lineCount = 0;
        int sectionStart = rectangles[0][startIndex];
        int sectionEnd = rectangles[0][endIndex];

        // Iterate through rectangles and count number of lines
        for (const auto& rect : rectangles) {
            if (rect[startIndex] < sectionEnd) {
                // Extend the current section
                sectionEnd = std::max(rect[endIndex], sectionEnd);
            } else {
                // Start a new section
                lineCount++;
                sectionStart = rect[startIndex];
                sectionEnd = rect[endIndex];
            }
        }

        // Check if we have more than 2 lines, which means at least two cuts can be made
        return lineCount >= 2;
    }
};