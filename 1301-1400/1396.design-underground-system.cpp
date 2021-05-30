/*
 * @lc app=leetcode id=1396 lang=cpp
 *
 * [1396] Design Underground System
 */

// @lc code=start
class UndergroundSystem {
private:    
    unordered_map<int, pair<string,int>> check;
    unordered_map<string, pair<double,int>> mp;
public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        check[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string route = check[id].first + " " + stationName;
        mp[route].first += (t - check[id].second);
        mp[route].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + " " + endStation;
        return mp[route].first/mp[route].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// @lc code=end

