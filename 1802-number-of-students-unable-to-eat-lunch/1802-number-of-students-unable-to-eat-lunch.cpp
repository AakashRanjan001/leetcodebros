class Solution 
{
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        int arr[2] = {0};
        int remain = sandwiches.size();

        for(int c : students)
        {
            arr[c] += 1;
        }

        for(int sand : sandwiches)
        {
            if(arr[sand] == 0) break;
            if(remain == 0) break;

            arr[sand] -= 1;
            remain--;
        }

        return remain;
    }
};
