/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * @brief Given an absolute path for a file (Unix-style), simplify it. Or in
 * other words, convert it to the canonical path.
 *
 * In a UNIX-style file system, a period . refers to the current directory.
 * Furthermore, a double period .. moves the directory up a level. For more
 * information, see: Absolute path vs relative path in Linux/Unix. In this
 * problem, the canonical path should have the following format:
 * - The path starts with a single slash /.
 * - Any two directories are separated by a single slash /.
 * - The path does not end with a trailing /.
 * - The path only contains the directories on the path from the root directory
 * to the target file or directory (i.e., no period . or double period ..).
 * - Return the simplified canonical path.
 *
 * Algorithm Complexity:
 * - Time complexity: O(n)
 * - Space complexity: O(n)
 */

// @lc code=start
class Solution {
   public:
	string simplifyPath(string path) {
		if (!path.size())
			return "";
		path += '/';

		vector<string> p;
		string thisPath = "";

		for (const auto& i : path) {
			if (i == '/') {
				// If the path is "..", we need to move the directory up a
				// level.
				if (thisPath == "..") {
					if (!p.empty()) {
						p.pop_back();
					}
				}
				// If the path is ".", we refer to the current directory, do
				// nothing.
				else if (!thisPath.empty() && thisPath != ".") {
					p.push_back(thisPath);
				}
				thisPath.clear();
			} else {
				thisPath += i;
			}
		}

		thisPath = "";
		for (const auto& i : p) {
			thisPath += '/' + i;
		}

		return thisPath.size() ? thisPath : "/";
	}
};
// @lc code=end
