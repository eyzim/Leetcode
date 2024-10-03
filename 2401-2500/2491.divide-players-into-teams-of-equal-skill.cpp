/*
 * @lc app=leetcode id=2491 lang=cpp
 *
 * [2491] Divide Players Into Teams of Equal Skill
 *
 * @brief The implementation of the Solution class, which is used to divide the
 * players into teams of equal skill.
 *
 * The problem requires us to divide the players into teams of equal skill. Each
 * team consists of two players, and the sum of the skill levels of the two
 * players in each team should be equal. The Solution class provides a method,
 * dividePlayers, that takes a vector of integers skill as input and returns the
 * sum of the skill levels of the players in each team. If it is not possible to
 * divide the players into teams of equal skill, the method returns -1. The
 * method uses a hash map to store the available players and their skill levels.
 * It then iterates through the skill levels to find pairs of players whose sum
 * is equal to the target sum. If a pair is found, the skill levels of the
 * players are added to the result, and the players are removed from the hash
 * map. The method returns the result if all players are divided into teams of
 * equal skill; otherwise, it returns -1.
 *
 * Algorithm Complexity:
 * - The dividePlayers method has a time complexity of O(n), where n is the
 * number of players.
 * - The space complexity of the method is O(n), where n is the number of
 * players.
 */

// @lc code=start
class Solution {
   public:
	long long dividePlayers(vector<int>& skill) {
		// There are two players in each team
		int size = skill.size() >> 1;
		// To calculate the sum of each pair of players
		long long sum = (accumulate(skill.begin(), skill.end(), 0)) / size;
		long long ans = 0;

		// To store the available players
		unordered_map<int, int> mp;
		for (const auto& i : skill) {
			int target = sum - i;
			if (mp[target]) {
				ans += (i * target);
				mp[target]--;
				size--;
			} else {
				mp[i]++;
			}
		}

		// if the size is 0, which means we have successfully divided the
		// players into teams
		return size == 0 ? ans : -1;
	}
};
// @lc code=end
