/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder1 {
   private:
	vector<int> med;

   public:
	MedianFinder() {}

	void addNum(int num) {
		if (!med.size()) {
			med.push_back(num);
		} else {
			int start = 0, end = med.size() - 1;
			while (start <= end) {
				int mid = start + (end - start) / 2;
				if (med[mid] < num) {
					start = mid + 1;
				} else {
					end = mid - 1;
				}
			}
			med.insert(med.begin() + start, num);
		}
	}

	double findMedian() {
		int m = med.size();
		if (m % 2) {
			return med[m / 2];
		} else {
			return double((med[m / 2] + med[m / 2 - 1]) / 2.000);
		}
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
