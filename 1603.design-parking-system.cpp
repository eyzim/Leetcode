/*
 * @lc app=leetcode id=1603 lang=cpp
 *
 * [1603] Design Parking System
 */

// @lc code=start
class ParkingSystem {
private:
    int park[3];
public:
    ParkingSystem(int big, int medium, int small) {
        park[0] = big;
        park[1] = medium;
        park[2] = small;
    }
    
    bool addCar(int carType) {
        if(park[carType-1] == 0)
        {
            return 0;
        }
        park[carType-1]--;

        return 1;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end

