// class Solution {
// public:
//     double passGain(int pass , int total){
//          double currpassratio = (double)(pass/total);
//          double newpassratio = (double)(pass+1/total+1);

//          double diffpassratio = newpassratio - currpassratio;
//          return diffpassratio;

//     }
//     double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
//         priority_queue<pair<double ,pair<int,int>>>maxheap;
//         for(auto &c : classes){
//             int pass = c[0];
//             int total = c[1];
//             maxheap.push({passGain(pass,total),{pass,total}});
//         }

//         while(extraStudents--){

//             auto &[gain,classdetails] = maxheap.top();
//             maxheap.pop();
            
//             int pass = classdetails.first;
//             int total = classdetails.second;

//             pass++;
//             total++;
//             extraStudents--;

//               maxheap.push({passGain(pass,total),{pass,total}});
//         }

//         double averratio = 0.0;
//         while(!maxheap.empty()){
//             auto &[gain,classdetails] = maxheap.top();
//             maxheap.pop();

//             int pass = classdetails.first;
//             int total = classdetails.second;

//             averratio +=double(pass/total);
//         }
//         return averratio/classes.size();
//     }
// };





class Solution {
public:
    double passGain(int pass, int total) {
        double currPassRatio = (double)pass / total;
        double newPassRatio = (double)(pass + 1) / (total + 1);
        return newPassRatio - currPassRatio;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Max heap to store the classes by their potential gain in pass ratio
        priority_queue<pair<double, pair<int, int>>> maxHeap;

        // Populate the heap with initial pass gains for all classes
        for (const auto& c : classes) {
            int pass = c[0], total = c[1];
            maxHeap.push({passGain(pass, total), {pass, total}});
        }

        // Distribute the extra students
        while (extraStudents > 0) {
            auto [gain, classInfo] = maxHeap.top();
            maxHeap.pop();

            int pass = classInfo.first;
            int total = classInfo.second;

            // Add one student to the class with the max gain
            pass++;
            total++;
            extraStudents--;

            // Recalculate the gain and push the updated class back to the heap
            maxHeap.push({passGain(pass, total), {pass, total}});
        }

        // Calculate the final average pass ratio
        double totalRatio = 0.0;
        while (!maxHeap.empty()) {
            auto [gain, classInfo] = maxHeap.top();
            maxHeap.pop();

            int pass = classInfo.first;
            int total = classInfo.second;

            totalRatio += (double)pass / total;
        }

        return totalRatio / classes.size();
    }
};
