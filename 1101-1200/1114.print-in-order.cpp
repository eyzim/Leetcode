/*
 * @lc app=leetcode id=1114 lang=cpp
 *
 * [1114] Print in Order
 *
 * @brief The implementation of the Foo class, which is used to print the
 * strings "first", "second", and "third" in order.
 *
 * Implement a class Foo that has the following solutions:
 * 1. Using a vector to store the printed status.
 * 2. Using mutex and condition_variable to synchronize the threads.
 * 3. Using atomic to synchronize the threads.
 * 4. Using atomic_flag to synchronize the threads.
 *
 * The Foo class provides three methods, first, second, and third, which take a
 * function as input and print the strings "first", "second", and "third" in
 * order. The methods are called by three different threads, each calling one of
 * the methods. The goal is to ensure that the strings are printed in the order
 * "first", "second", "third".
 *
 * Algorithm Complexity:
 * - All the methods have a time complexity of O(1).
 * - The space complexity of the class is O(1).
 */

// @lc code=start
// solution 1: using vector to store the printed status
class Foo {
   private:
	vector<bool> printed;

   public:
	Foo() : printed(3, false) {}

	void first(function<void()> printFirst) {
		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		printed[0] = true;
	}

	void second(function<void()> printSecond) {
		while (!printed[0]) {
		}
		// printSecond() outputs "second". Do not change or remove this line.
		printSecond();
		printed[1] = true;
	}

	void third(function<void()> printThird) {
		while (!printed[1]) {
		}
		// printThird() outputs "third". Do not change or remove this line.
		printThird();
		printed[2] = true;
	}
};

// solution 2: using mutex and condition_variable to synchronize the threads
class Foo {
	condition_variable cv;
	mutex mtx;
	int currentPrint;

   public:
	Foo() { currentPrint = 1; }

	void first(function<void()> printFirst) {
		unique_lock<mutex> lock(mtx);
		currentPrint = 2;
		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		cv.notify_all();
	}

	void second(function<void()> printSecond) {
		unique_lock<mutex> lock(mtx);
		cv.wait(lock, [&]() { return currentPrint == 2; });
		currentPrint = 3;
		// printSecond() outputs "second". Do not change or remove this line.
		printSecond();
		cv.notify_one();
	}

	void third(function<void()> printThird) {
		unique_lock<mutex> lock(mtx);
		cv.wait(lock, [&]() { return currentPrint == 3; });
		// printThird() outputs "third". Do not change or remove this line.
		printThird();
	}
};

// solution 3: using atomic to synchronize the threads
class Foo {
	atomic<int> turn = 1;

   public:
	Foo() {}

	void first(function<void()> printFirst) {
		while (turn != 1) {
			this_thread::yield();
		}
		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		turn++;
	}

	void second(function<void()> printSecond) {
		while (turn != 2) {
			this_thread::yield();
		}
		// printSecond() outputs "second". Do not change or remove this line.
		printSecond();
		turn++;
	}

	void third(function<void()> printThird) {
		while (turn != 3) {
			this_thread::yield();
		}
		// printThird() outputs "third". Do not change or remove this line.
		printThird();
	}
};

// solution 4: using atomic_flag to synchronize the threads
class Foo {
	atomic_flag flag1 = ATOMIC_FLAG_INIT;
	atomic_flag flag2 = ATOMIC_FLAG_INIT;

   public:
	Foo() {
		flag1.clear();
		flag2.clear();
	}

	void first(function<void()> printFirst) {
		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		flag1.test_and_set();
	}

	void second(function<void()> printSecond) {
		while (!flag1.test_and_set()) {
		}
		// printSecond() outputs "second". Do not change or remove this line.
		printSecond();
		flag2.test_and_set();
	}

	void third(function<void()> printThird) {
		while (!flag2.test_and_set()) {
		}
		// printThird() outputs "third". Do not change or remove this line.
		printThird();
	}
};

// @lc code=end
