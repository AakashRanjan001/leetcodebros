class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        struct PosInfo {
            int index;
            int pos;
            int life;
            char dir;
        };

        int n = positions.size();
        vector<PosInfo> robots(n);

        for(int i = 0; i < n; i++){
            robots[i] = {i, positions[i], healths[i], directions[i]};
        }

        sort(robots.begin(), robots.end(), [](const PosInfo& a, const PosInfo& b) {
            return a.pos < b.pos;
        });

        stack<PosInfo> s;
        for(auto& robot : robots){
            while(!s.empty() && s.top().dir == 'R' && robot.dir == 'L') {
                if(s.top().life > robot.life) {
                    s.top().life--;
                    robot.life = 0;
                    break;
                } else if(s.top().life < robot.life) {
                    robot.life--;
                    s.pop();
                } else {
                    s.pop();
                    robot.life = 0;
                    break;
                }
            }
            if(robot.life > 0) {
                s.push(robot);
            }
        }

        vector<PosInfo> survived;
        while(!s.empty()){
            survived.push_back(s.top());
            s.pop();
        }

        sort(survived.begin(), survived.end(), [](const PosInfo& a, const PosInfo& b) {
            return a.index < b.index;
        });

        vector<int> res;
        for(auto& robot : survived) {
            res.push_back(robot.life);
        }

        return res;
    }
};
