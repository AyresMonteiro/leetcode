// I couldn't figure it out for myself, but I was able to understand the
// solution. Thanks to withaarzoo solution post.
// It consists of marking indices of array that has smaller values (
// potential starting points of a ramp) than the last smaller value.
// Then, we start iterating from the farthest value of array, allowing us
// to possibly find the widest ramp by checking the potential starting
// points.
// Because of the fact that indices are ordered in a stack that starts from
// the greater value, we need to check if the previous ramp was interrupted
// and decrease the pointer of the farthest value until we find a value that
// that is greater than the current potential starting point.
// Also because of the order of the stack, we can be sure that we are
// grabbing the widest value possible for the value of the current right
// pointer.

// Results:
// Elapsed time: 54ms | Beats 42.86% at the submit time
// Memory: 46.80MB | Beats 45.61% at the submit time

// Code Complexity:
// O(n) time complexity
// O(n) space complexity

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int length = nums.size(), maxRamp = 0;
        stack<int> indices;

        for (int i = 0; i < length; i++) {
            if (indices.empty() || nums[indices.top()] > nums[i]) {
                indices.push(i);
            }
        }

        for (int right = length - 1; right >= 0; right--) {
            while (!indices.empty() && nums[indices.top()] <= nums[right]) {
                maxRamp = max(maxRamp, right - indices.top());
                indices.pop();
            }
        }

        return maxRamp;
    }
};
