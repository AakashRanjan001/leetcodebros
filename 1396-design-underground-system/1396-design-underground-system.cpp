class UndergroundSystem {
public:
     unordered_map<int,pair<string,int>> checkin_mp;  // id -->(entrystation , entrytime)
     unordered_map<string,pair<int,int>> checkout_mp;  // route-->(toatltime , count)
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin_mp[id] ={stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
         string startstation = checkin_mp[id].first;//station 
         int  entrytime = checkin_mp[id].second;
         string endstation = stationName;
         int endtime =t;
         string route = startstation + "_" + endstation;
         int totaltime = t - entrytime;

         checkout_mp[route].first+=totaltime;  // duration between station A and B
         checkout_mp[route].second+=1; // count of people from A--->B

         checkin_mp.erase(id);

    }
    
    double getAverageTime(string startStation, string endStation) {
         string route = startStation + "_" + endStation;
         auto &it = checkout_mp[route];
         int totaltime = it.first;
         int count = it.second;
         return (double)totaltime/count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */