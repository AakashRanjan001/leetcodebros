
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        //arrivals and dept. arrays

        vector<int> arr;
        vector<int> dept;

        for(auto x : intervals){
            arr.push_back(x[0]);
            dept.push_back(x[1]);
        }

        sort(arr.begin(), arr.end());
        sort(dept.begin(), dept.end());

        int ans = 1, count = 1;

        int n = arr.size();
        int i = 1, j = 0;
        while(i < n && j < n){
            if(arr[i] <= dept[j]){
                count++;
                i++;
            }
            else{
                count--;
                j++;
            }

            ans = max(ans,count);
        }

        return ans;

    }
};