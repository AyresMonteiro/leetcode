// I didn't read that the solution could be done in any order.
// I was trying to find the indexes the order they appear in the vector.

// Results:
// Elapsed time: 11ms | Beats 63.20% at the submit time
// Memory: 18.47MB | Beats 5.01% at the submit time

// Code Complexity:
// O(n) time complexity
// O(n) space complexity

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;

        solution.reserve(2);

        set<int> nums_set(nums.begin(), nums.end());

        int next = -1;
        int vectorLength = nums.size();

        map<int, int> counters;

        for (int num : nums) {
            map<int, int>::iterator it;

            it = counters.find(num);

            if (it == counters.end()) {
                counters.insert(make_pair(num, 1));
            } else {
                it->second++;
            }
        }

        for (int i = 0; i < vectorLength; i++) {
            if (next != -1 && nums[i] == next) {
                solution.push_back(i);
                break;
            }

            if (target - nums[i] == nums[i] && counters.find(nums[i])->second < 2) {
                continue;
            }

            if (nums_set.find(target - nums[i]) == nums_set.end()) continue;

            solution.push_back(i);
        }

        return solution;
    }
};
