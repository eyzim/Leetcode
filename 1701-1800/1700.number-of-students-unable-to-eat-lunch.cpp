/*
 * @lc app=leetcode id=1700 lang=cpp
 *
 * [1700] Number of Students Unable to Eat Lunch
 *
 * @brief The implementation of the Solution class, which is used to count the
 * number of students unable to eat lunch.
 *
 * The Solution class provides a method, countStudents, that takes two vectors
 * of integers, students and sandwiches, as input and returns the number of
 * students unable to eat lunch. The method sets up two queues, one for students
 * and one for sandwiches. It then iterates through the queues, checking if the
 * front of the queue is the same for both queues. If the front of the queue is
 * not the same, the student is marked as checked, and the student is moved to
 * the back of the queue. If the front of the queue is the same, the student is
 * removed from both queues, and the point is reset to 0. The method returns the
 * size of the queue of students.
 *
 * Note that this solution is as same as question 1047. Remove All Adjacent
 * Duplicates In String.
 *
 * Algorithm Complexity:
 * - The countStudents method has a time complexity of O(n), where n is the
 * number of students.
 * - The space complexity of the method is O(n).
 */

// @lc code=start
class Solution {
   public:
	int countStudents(vector<int>& students, vector<int>& sandwiches) {
		// set up two queues, one for students and one for sandwiches
		queue<int> q, food;
		for (auto i : students)
			q.push(i);
		for (auto i : sandwiches)
			food.push(i);
		int point = 0;

		// point is used to keep track of the number of students that have been
		// checked
		while (point < q.size()) {
			// if the front of the queue is not the same as the front of the
			// food
			if (q.front() != food.front()) {
				int x = q.front();
				q.pop();
				q.push(x);
				// mark the student as checked
				point++;
			} else {
				q.pop();
				food.pop();
				// reset the point, cause we have found a student that can eat,
				// then we need to check from the beginning
				point = 0;
			}
		}

		return q.size();
	}
};
// @lc code=end
