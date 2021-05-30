/*
 * @lc app=leetcode id=1465 lang=cpp
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 *
 * @brief The implementation of the Solution class, which is used to calculate
 * the maximum area of a piece of cake after cutting it horizontally and
 * vertically.
 *
 * The Solution class provides a method, maxArea, that takes the width and
 * height of the cake as input, along with the horizontal and vertical cuts. The
 * method calculates the maximum area of a piece of cake after cutting it
 * horizontally and vertically. The method first sorts the horizontal and
 * vertical cuts and then calculates the maximum height and width of the pieces.
 * The maximum area is then calculated as the product of the maximum height and
 * width, modulo 10^9 + 7, and returned as the output. Mind that the modulo
 * operation is used to prevent integer overflow.
 *
 * Algorithm Complexity:
 * - The maxArea method has a time complexity of O(nlogn), where n is the number
 * of horizontal and vertical cuts.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution {
   public:
	const long long int mod = 1000000007;
	int maxArea(int h,
				int w,
				vector<int>& horizontalCuts,
				vector<int>& verticalCuts) {
		horizontalCuts.insert(horizontalCuts.end(), {0, h});
		sort(horizontalCuts.begin(), horizontalCuts.end());

		verticalCuts.insert(verticalCuts.end(), {0, w});
		sort(verticalCuts.begin(), verticalCuts.end());

		long long int maxh = 0, maxw = 0;
		for (auto i = 1; i < horizontalCuts.size(); i++) {
			int th = horizontalCuts[i] - horizontalCuts[i - 1];
			if (th > maxh)
				maxh = th;
		}

		for (auto i = 1; i < verticalCuts.size(); i++) {
			int tw = verticalCuts[i] - verticalCuts[i - 1];
			if (tw > maxw)
				maxw = tw;
		}

		return (int)(maxh % mod * maxw % mod);
	}
};
// @lc code=end
