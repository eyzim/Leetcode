/*
 * @lc app=leetcode id=1381 lang=cpp
 *
 * [1381] Design a Stack With Increment Operation
 *
 * @brief The implementation of the CustomStack class, which is used to
 * implement a stack with increment operation.
 *
 * The CustomStack class provides the following methods:
 * - CustomStack(int maxSize): Initializes the stack with a maximum size of
 * maxSize.
 * - void push(int x): Adds an integer x to the top of the stack if the stack
 * hasn't reached the maxSize.
 * - int pop(): Removes and returns the top element of the stack. If the stack
 * is empty, return -1.
 * - void increment(int k, int val): Increments the bottom k elements of the
 * stack by val. If there are fewer than k elements in the stack, increment all
 * elements.
 * We use a vector to store the elements of the stack and implement the push,
 * pop, and increment methods accordingly. The push method adds an element to
 * the top of the stack if the stack hasn't reached its maximum size. The pop
 * method removes and returns the top element of the stack. The increment method
 * increments the bottom k elements of the stack by val. If there are fewer than
 * k elements in the stack, it increments all elements.
 *
 * Algorithm Complexity:
 * - The push method has a time complexity of O(1).
 * - The pop method has a time complexity of O(1).
 * - The increment method has a time complexity of O(k), where k is the number
 * of elements to increment.
 * - The space complexity of the CustomStack class is O(n), where n is the
 * maximum size of the stack.
 */

// @lc code=start
class CustomStack {
   private:
	vector<int> v;
	int s;

   public:
	CustomStack(int maxSize) { s = maxSize; }

	void push(int x) {
		if (v.size() < s) {
			v.push_back(x);
		}
	}

	int pop() {
		if (!v.size())
			return -1;
		int back = v.back();
		v.erase(v.end());
		return back;
	}

	void increment(int k, int val) {
		for (int i = 0; i < v.size() && i < k; i++) {
			v[i] += val;
		}
	}
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// @lc code=end
