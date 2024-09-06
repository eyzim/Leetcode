/*
 * @lc app=leetcode id=1845 lang=cpp
 *
 * [1845] Seat Reservation Manager
 * **Same as problem 2336**
 *
 * @brief The implementation of the SeatManager class, which is used to manage
 * seat reservations.
 *
 * The SeatManager class provides a constructor, SeatManager, that takes an
 * integer, n, as input and initializes the current seat number, cur, to 1 and a
 * set, mp, to store the reserved seat numbers. It also provides two methods,
 * reserve and unreserve, to reserve and unreserve seats, respectively. The
 * reserve method checks if there are any reserved seats in the set, mp, and
 * returns the smallest reserved seat number if there are any, or increments the
 * current seat number, cur, if there are no reserved seats. The unreserve
 * method adds the seat number to the set, mp.
 *
 * Algorithm Complexity:
 * - The reserve method has a time complexity of O(log n) for the set
 * operations.
 * - The unreserve method has a time complexity of O(log n) for the set
 * operations.
 * - The space complexity of the SeatManager class is O(n).
 */

// @lc code=start
class SeatManager {
   private:
	int cur;
	set<int> mp;

   public:
	SeatManager(int n) { cur = 1; }

	int reserve() {
		if (mp.size()) {
			int t = *mp.begin();
			mp.erase(t);
			return t;
		} else {
			return cur++;
		}
	}

	void unreserve(int seatNumber) { mp.insert(seatNumber); }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
// @lc code=end
