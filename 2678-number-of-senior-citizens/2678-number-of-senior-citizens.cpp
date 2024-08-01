class Solution {
public:
    int countSeniors(vector<string>& details) {
         int n = details.size();
        int cnt = 0;

        for(int i = 0; i < n; ++i) {
            string temp = details[i];

            // Assuming that the age is always at the same position
            if (temp.size() > 12) { // Check if the string is long enough
                int age = stoi(temp.substr(11, 2)); // Convert the substring to an integer

                if(age > 60) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};