/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 *
 * @brief The implementation of the MyQueue class, which is used to implement a
 * queue using stacks.
 *
 * The MyQueue class provides methods to push, pop, peek, and check if the queue
 * is empty. The push method pushes an integer onto the queue, the pop method
 * removes the element from the front of the queue and returns it, the peek
 * method returns the element at the front of the queue, and the empty method
 * returns true if the queue is empty.
 * To implement the queue using stacks, we use two stacks, st and temp. When we
 * push an element onto the queue, we first move all the elements from st to
 * temp, push the new element onto st, and then move all the elements from temp
 * back to st. This way, the element that was pushed first is at the bottom of
 * the stack, and the element that was pushed last is at the top of the stack.
 *
 * Algorithm Complexity:
 * - The push method has a time complexity of O(n), where n is the number of
 * elements in the queue.
 * - The pop, peek, and empty methods have a time complexity of O(1).
 * - The space complexity of the MyQueue class is O(n).
 */

// @lc code=start
class MyQueue {
   private:
	stack<int> st, temp;

   public:
	MyQueue() {}

	void push(int x) {
		while (!st.empty()) {
			temp.push(st.top());
			st.pop();
		}
		st.push(x);
		while (!temp.empty()) {
			st.push(temp.top());
			temp.pop();
		}
	}

	int pop() {
		int p = st.top();
		st.pop();
		return p;
	}

	int peek() { return st.top(); }

	bool empty() { return st.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
