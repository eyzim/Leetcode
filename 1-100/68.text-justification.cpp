/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 *
 * @brief The implementation of the Solution class, which is used to justify
 * text.
 *
 * The Solution class provides a method, fullJustify, that takes a vector of
 * words and an integer maxWidth as input and returns a vector of strings that
 * represent the justified text. The fullJustify method formats the words into
 * lines of text such that each line has exactly maxWidth characters. The words
 * in each line are separated by spaces, and the extra spaces are distributed as
 * evenly as possible between the words. If a line has only one word, the extra
 * spaces are added to the right side of the word. If a line is the last line of
 * the text, the extra spaces are added between the words.
 *
 * Algorithm Complexity:
 * - The fullJustify method has a time complexity of O(n), where n is the number
 * of words in the input vector, as we iterate through all the words in the
 * input vector. Additionally, the time complexity of the middle and left helper
 * functions is O(n), where n is the number of words in the input vector. At
 * last, the time complexity of the whole class is O(n^2).
 * - The space complexity of the fullJustify method is O(n), where n is the
 * number of words in the input vector.
 */

// @lc code=start
class Solution1 {
   private:
	// Helper function to justify the text with extra spaces between the words.
	string middle(vector<string>& words, int start, int end, int space) {
		string result = "";

		for (auto i = start; i < end; i++) {
			result += words[i];
			int s = space / (end - i) + (space % (end - i) != 0);
			result.append(s, ' ');
			space -= s;
		}
		result += words[end];

		return result;
	}

	// Helper function to justify the text with extra spaces at the end of the
	// line.
	string left(vector<string>& words, int start, int end, int space) {
		string result;

		for (int i = start; i <= end; i++) {
			result += words[i];
			if (i < end) {
				result.append(1, ' ');
			}
		}
		result.append(space - (end - start), ' ');

		return result;
	}

   public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> ans;
		int start = 0, end = 0;

		while (start < words.size()) {
			// Find the words that can fit in the current line.
			int cur = words[start].size();
			end = start;
			int space = maxWidth - words[start].size();

			while (end + 1 < words.size() &&
				   cur + 1 + words[end + 1].size() <= maxWidth) {
				cur += words[end + 1].size() + 1;
				space -= words[end + 1].size();
				end++;
			}

			// Construct the line based on the words that can fit in the current
			// line.
			string line = "";
			if (end == start || end + 1 == words.size()) {
				line = left(words, start, end, space);
			} else {
				line = middle(words, start, end, space);
			}

			ans.push_back(line);
			start = end + 1;
		}

		return ans;
	}
};

class Solution2 {
   public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> result;
		int n = words.size();
		int i = 0;

		while (i < n) {
			// Determine the range of words to be included in the current line
			int lineLength = words[i].size();
			int last = i + 1;
			while (last < n &&
				   lineLength + 1 + words[last].size() <= maxWidth) {
				lineLength +=
					1 + words[last].size();	 // 1 for space between words
				last++;
			}

			// Build the line
			string line = words[i];
			int spaceSlots = last - i - 1;

			if (last == n || spaceSlots == 0) {
				// Left-justify the last line or a line with a single word
				for (int j = i + 1; j < last; ++j) {
					line += " " + words[j];
				}
				line.append(maxWidth - line.size(),
							' ');  // Fill remaining space
			} else {
				// Fully justify the line
				int spaces = (maxWidth - lineLength + spaceSlots) / spaceSlots;
				int extraSpaces =
					(maxWidth - lineLength + spaceSlots) % spaceSlots;

				for (int j = i + 1; j < last; ++j) {
					line.append(spaces + (j - i <= extraSpaces ? 1 : 0),
								' ');  // Add 1 extra space if in the first
									   // `extraSpaces` slots
					line += words[j];
				}
			}

			result.push_back(line);
			i = last;
		}

		return result;
	}
};

// @lc code=end
