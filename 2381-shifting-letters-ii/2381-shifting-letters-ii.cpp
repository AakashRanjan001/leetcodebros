class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        // for(int i=0;i<shifts.size();i++){
        //      int start_index = shifts[i][0];
        //      int end_index = shifts[i][1];
        //      int direction = shifts[i][2];
             
        //      for(int j=start_index;j<=end_index;j++){
        //          if(direction == 1){
        //             s[j] = (s[j] - 'a' + 1)%26 + 'a';
        //          }
        //          else{
        //             s[j] = (s[j] - 'a' + 25)%26 + 'a';
        //          }
        //      }

        // }
        // return s;


          int n = s.size();
        vector<int> shift(n + 1, 0);

        for (auto& it : shifts) 
        {
            int start = it[0];
            int end = it[1];
            int dir = it[2];
            // Forward
            if(dir == 1)
            {
                shift[start] += 1;
                shift[end + 1] -= 1;    
            }
            // Backward
            else
            {
                shift[start] += -1;
                shift[end + 1] -= -1;    
            }
        }

        // Use a prefix sum on the shift array to calculate the net shift for each character.
        int current_shift = 0;
        for (int i = 0; i < n; ++i) 
        {
            current_shift += shift[i];
            shift[i] = current_shift;
        }

        for (int i = 0; i < n; ++i) 
        {
            // To ensure non-negative values within the alphabet range.
            int total_shift = (shift[i] % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + total_shift) % 26;
        }

        return s;
    }
};