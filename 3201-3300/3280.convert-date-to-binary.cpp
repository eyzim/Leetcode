/*
 * @lc app=leetcode id=3280 lang=cpp
 *
 * [3280] Convert Date to Binary
 */

// @lc code=start
class Solution {
   private:
	// Convert a decimal number to binary
	string toBinary(int d) {
		string bin = "";

		while (d) {
			// Convert the remainder to a string and add it to the beginning of
			// the binary string
			bin = to_string(d % 2) + bin;
			d /= 2;
		}

		return bin;
	}

   public:
	string convertDateToBinary(string date) {
		date += "-";
		string p = "", ans = "";

		for (auto i : date) {
			if (i == '-') {
				ans += toBinary(stoi(p)) + '-';
				p.clear();
			} else {
				p += i;
			}
		}

		// Remove the last character "-" from the string
		ans.pop_back();
		return ans;
	}
};
// @lc code=end
