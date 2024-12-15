class Solution {
public:
    double passGain(int pass , int total){
         double currpassratio = (double)(pass/total);
         double newpassratio = (double)(pass+1/total+1);

         double diffpassratio = newpassratio - currpassratio;
         return diffpassratio;

    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue<pair<double ,pair<int,int>>>maxheap;
        for(auto &c : classes){
            int pass = c[0];
            int total = c[1];
            maxheap.push({passGain(pass,total),{pass,total}});
        }

        while(extraStudents--){

            auto &[gain,classdetails] = maxheap.top();
            maxheap.pop();
            
            int pass = classdetails.first;
            int total = classdetails.second;

            pass++;
            total++;
            extraStudents--;

              maxheap.push({passGain(pass,total),{pass,total}});
        }

        double averratio = 0.0;
        while(!maxheap.empty()){
            auto &[gain,classdetails] = maxheap.top();
            maxheap.pop();

            int pass = classdetails.first;
            int total = classdetails.second;

            averratio +=double(pass/total);
        }
        return averratio/classes.size();
    }
};