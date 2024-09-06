/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 *
 * @brief The implementation of the MyStack class, which is used to implement a
 * stack using queues.
 *
 * The MyStack class provides four methods:
 * - push: that takes an integer, x, as input and pushes it onto the
 * stack. The method first moves all elements from q to temp, pushes x onto q,
 * and then moves all elements from temp back to q.
 * - pop: that pops the top element from the stack and returns it.
 * - top: that returns the top element of the stack.
 * - empty: that returns true if the stack is empty and false
 * otherwise.
 *
 * Algorithm Complexity:
 * - The push method has a time complexity of O(n), where n is the number of
 * elements in the stack.
 * - The pop, top, and empty methods have a time complexity of O(1).
 * - The space complexity of the MyStack class is O(n).
 */

// @lc code=start
class MyStack {
   private:
	queue<int> q, temp;

   public:
	MyStack() {}

	void push(int x) {
		while (!q.empty()) {
			temp.push(q.front());
			q.pop();
		}
		q.push(x);
		while (!temp.empty()) {
			q.push(temp.front());
			temp.pop();
		}
	}

	int pop() {
		int p = q.front();
		q.pop();
		return p;
	}

	int top() { return q.front(); }

	bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
