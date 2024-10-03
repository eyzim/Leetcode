/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 *
 * @brief Design your implementation of the circular double-ended queue (deque).
 *
 * We can use a vector or a deque to implement the circular deque. The vector is
 * a bit faster than the deque.
 *
 * Algorithm Complexity:
 * 1. Using vector:
 * - Time complexity: O(1) for all operations.
 * - Space complexity: O(n) where n is the size of the deque.
 * 2. Using deque:
 * - Time complexity: O(1) for all operations.
 * - Space complexity: O(n) where n is the size of the deque.
 */

// @lc code=start
// Using vector
class MyCircularDeque {
   private:
	vector<int> q;
	int s;

   public:
	MyCircularDeque(int k) { s = k; }

	bool insertFront(int value) {
		if (q.size() == s)
			return false;
		q.insert(q.begin(), value);
		return true;
	}

	bool insertLast(int value) {
		if (q.size() == s)
			return false;
		q.push_back(value);
		return true;
	}

	bool deleteFront() {
		if (!q.size())
			return false;
		q.erase(q.begin());
		return true;
	}

	bool deleteLast() {
		if (!q.size())
			return false;
		q.erase(q.end());
		return true;
	}

	int getFront() {
		if (!q.size())
			return -1;
		return q[0];
	}

	int getRear() {
		if (!q.size())
			return -1;
		return q.back();
	}

	bool isEmpty() { return q.size() ? false : true; }

	bool isFull() { return q.size() == s; }
};

// Using deque
class MyCircularDeque {
   private:
	deque<int> q;
	int s;

   public:
	MyCircularDeque(int k) { s = k; }

	bool insertFront(int value) {
		if (q.size() == s)
			return false;
		q.push_front(value);
		return true;
	}

	bool insertLast(int value) {
		if (q.size() == s)
			return false;
		q.push_back(value);
		return true;
	}

	bool deleteFront() {
		if (!q.size())
			return false;
		q.pop_front();
		return true;
	}

	bool deleteLast() {
		if (!q.size())
			return false;
		q.pop_back();
		return true;
	}

	int getFront() {
		if (!q.size())
			return -1;
		return q.front();
	}

	int getRear() {
		if (!q.size())
			return -1;
		return q.back();
	}

	bool isEmpty() { return q.size() ? false : true; }

	bool isFull() { return q.size() == s; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end
