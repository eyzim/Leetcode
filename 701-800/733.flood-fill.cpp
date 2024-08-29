/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 *
 * @brief The implementation of the Solution class, which is used to fill a
 * region in an image with a new color.
 *
 * The Solution class provides a method, floodFill, that takes a 2D vector of
 * integers, an integer sr, an integer sc, and an integer newColor as input and
 * returns a 2D vector of integers. The method fills the region starting from
 * the pixel at the row and column specified by sr and sc with the new color
 * newColor. The method uses a depth-first search (DFS) approach to fill the
 * region with the new color. The method first checks if the pixel at the row
 * and column specified by sr and sc is the same as the new color. If it is, the
 * method returns the original image. Otherwise, the method calls a helper
 * function, dfs, to fill the region with the new color. The dfs function
 * recursively fills the region by changing the color of the current pixel and
 * calling itself on the neighboring pixels.
 *
 * Algorithm Complexity:
 * - The floodFill method has a time complexity of O(n), where n is the number
 * of pixels in the image.
 * - The space complexity of the method is O(1), which does not include the
 * space used by the output.
 */

// @lc code=start
class Solution {
   private:
	void dfs(vector<vector<int>>& image,
			 int sr,
			 int sc,
			 int& orig,
			 int& color) {
		// If the current pixel is out of bounds, return.
		if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() ||
			image[sr][sc] != orig || image[sr][sc] == color)
			return;

		// Change the color of the current pixel.
		image[sr][sc] = color;
		// Recursively call the method on the neighboring pixels.
		dfs(image, sr + 1, sc, orig, color);
		dfs(image, sr - 1, sc, orig, color);
		dfs(image, sr, sc + 1, orig, color);
		dfs(image, sr, sc - 1, orig, color);
	}

   public:
	vector<vector<int>> floodFill(vector<vector<int>>& image,
								  int sr,
								  int sc,
								  int color) {
		if (image.size() == 0)
			return image;

		int orig = image[sr][sc];

		for (auto i = 0; i < image.size(); i++) {
			for (auto j = 0; j < image[0].size(); j++) {
				if (image[sr][sc] == orig) {
					dfs(image, sr, sc, orig, color);
				}
			}
		}

		return image;
	}
};
// @lc code=end
