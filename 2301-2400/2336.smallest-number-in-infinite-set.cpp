/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 * **Same as problem 1845**
 *
 * @brief The implementation of the SmallestInfiniteSet class, which is used to
 * find the smallest number in the infinite set.
 *
 * The SmallestInfiniteSet class has two methods:
 * - popSmallest(): Returns the smallest number in the set. If the set is empty,
 * it returns the current number and increments the current number by one. I've
 * used a set to store the numbers that are less than the current number. The
 * popSmallest() method returns the smallest number from the set if it is not
 * empty; otherwise, it returns the current number and increments the current
 * number by one.
 * - addBack(int num): Adds the number to the set if it is less than the current
 * number. I've used a set to store the numbers that are less than the current
 * number. The addBack(int num) method adds the number to the set if it is less
 * than the current number.
 * Mind that set and unordered_set are different. The set is implemented using a
 * red-black tree, which is a self-balancing binary search tree. The set is
 * ordered, and the elements are stored in sorted order. The unordered_set is
 * implemented using a hash table, and the elements are stored in an arbitrary
 * order.
 *
 * Algorithm Complexity:
 * - The popSmallest() method has an average time complexity of O(log n), where
 * n is the size of the set.
 * - The addBack(int num) method has an average time complexity of O(log n),
 * where n is the size of the set.
 */

// @lc code=start
class SmallestInfiniteSet {
   private:
	int cur;
	set<int> mp;

   public:
	SmallestInfiniteSet() { cur = 1; }

	int popSmallest() {
		if (mp.size()) {
			int smallest = *mp.begin();
			mp.erase(smallest);
			return smallest;
		}
		return cur++;
	}

	void addBack(int num) {
		if (num < cur) {
			mp.insert(num);
		}
	}
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end
