/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * @brief The implementation of the Solution class, which is used to search for
 * a target value in a 2D matrix.
 *
 * The solution1 class provides a method, searchMatrix, that takes a vector of
 * vectors of integers and an integer target as input and returns true if the
 * target value is present in the matrix. The method uses a binary search
 * approach to find the target value in the matrix. The method first searches
 * for the target value in the first column of the matrix. If the target value
 * is found in the first column, the method returns true. If the target value is
 * not found in the first column, the method searches for the target value in
 * the row where the target value might be present. If the target value is found
 * in the row, the method returns true. If the target value is not found in the
 * row, the method returns false.
 * The solution2 class provides a method, searchMatrix, that takes a vector of
 * integers and an integer target as input and returns true if the target value
 * is present in the matrix. The method uses a binary search approach to find
 * the target value in the matrix. The method first initializes the start and
 * end indices of the matrix. The method then uses a while loop to search for
 * the target value in the matrix. The method calculates the mid index of the
 * matrix and compares the target value with the value at the mid index. If the
 * target value is found at the mid index, the method returns true. If the
 * target value is not found at the mid index, the method updates the start and
 * end indices of the matrix based on the comparison of the target value with
 * the value at the mid index. The method continues the search until the target
 * value is found or the start index is greater than the end index. If the
 * target value is not found in the matrix, the method returns false.
 *
 * Algorithm Complexity:
 * 1. Solution1:
 * - The searchMatrix method has a time complexity of O(log(m) + log(n)), where
 * m is the number of rows and n is the number of columns in the matrix.
 * - The space complexity of the method is O(1).
 * 2. Solution2:
 * - The searchMatrix method has a time complexity of O(log(m*n)), where m is
 * the number of rows and n is the number of columns in the matrix.
 * - The space complexity of the method is O(1).
 */

// @lc code=start
class Solution1 {
   public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		// Find the row where the target might be present
		int startRow = 0, endRow = matrix.size() - 1;
		while (startRow <= endRow) {
			int mid = startRow + ((endRow - startRow) >> 1);

			if (matrix[mid][0] == target) {
				return true;
			} else if (matrix[mid][0] > target) {
				endRow = mid - 1;
			} else {
				startRow = mid + 1;
			}
		}

		if (startRow)
			startRow--;

		// Find the target in the row
		int startCol = 0, endCol = matrix[0].size() - 1;
		while (startCol <= endCol) {
			int mid = startCol + ((endCol - startCol) >> 1);

			if (matrix[startRow][mid] == target) {
				return true;
			} else if (matrix[startRow][mid] > target) {
				endCol = mid - 1;
			} else {
				startCol = mid + 1;
			}
		}

		return false;
	}
};

class Solution2 {
   public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix[0].size();
		int start = 0;
		// The end index is the total number of elements in the matrix
		int end = matrix[0].size() * matrix.size() - 1;

		while (start <= end) {
			int mid = start + ((end - start) >> 1);

			// Calculate the row and column index of the mid element, and
			// compare the target value with the mid element
			if (matrix[mid / m][mid % m] == target) {
				return true;
			} else if (matrix[mid / m][mid % m] > target) {
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}

		return false;
	}
};
// @lc code=end
