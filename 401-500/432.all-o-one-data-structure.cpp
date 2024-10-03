/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 *
 * @brief Implement a data structure supporting some operations. It has two
 * methods: inc(key) - Increments the key by 1. If the key does not exist,
 * insert the key with value 1. dec(key) - Decrements the key by 1. If the key's
 * value is 1, remove it. If the key does not exist, do nothing. getMaxKey() -
 * Returns one of the keys with maximal value. If no element exists, return an
 * empty string. getMinKey() - Returns one of the keys with minimal value. If no
 * element exists, return an empty string.
 * We can use a hash map to store the frequency of each key. We can also use a
 * set to store the frequency and key. The set is sorted by frequency. We can
 * use the set to get the maximum and minimum frequency key. We can also use the
 * set to insert and delete the key.
 *
 * Algorithm Complexity:
 * - Time complexity: O(1) for inc, dec, getMaxKey, and getMinKey methods.
 * - Space complexity: O(n), where n is the number of keys.
 */

// @lc code=start
class AllOne {
   private:
	// Store string and its frequency
	unordered_map<string, int> mp;
	// Store frequency and string
	set<pair<int, string>> s;

   public:
	// Time complexity: O(1)
	AllOne() {}

	// Time complexity: O(logn), cause of set insert
	void inc(string key) {
		s.erase({mp[key], key});
		mp[key]++;
		s.insert({mp[key], key});
	}

	// Time complexity: O(logn), cause of set insert
	void dec(string key) {
		s.erase({mp[key], key});
		if (mp[key] == 1) {
			mp.erase(key);
		} else {
			mp[key]--;
			s.insert({mp[key], key});
		}
	}

	// Time complexity: O(1)
	string getMaxKey() {
		if (s.empty())
			return "";
		return s.rbegin()->second;
	}

	// Time complexity: O(1)
	string getMinKey() {
		if (s.empty())
			return "";
		return s.begin()->second;
	}
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end
