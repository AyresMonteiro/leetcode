// I couldn't realize that I was using only the size of
// the stacks to calculate the result, so I ended up using
// more memory than necessary by using containers instead
// of just integers to store the count of openings and
// closings.

// Results:
// Elapsed time: 0ms | Beats 100.00% at the submit time
// Memory: 8.04MB | Beats 15.76% at the submit time

// Code Complexity:
// O(n) time complexity
// O(n) space complexity

class Solution {
public:
    int minAddToMakeValid(string s) {
        if (s == "") return 0;

        stack<char> openings;
        stack<char> closings;

        for (char c : s) {
            switch(c) {
                case '(':
                    openings.push(c);
                    continue;
                case ')':
                    if(openings.empty()) {
                        closings.push(c);
                    } else {
                        openings.pop();
                    }
            }
        }

        return openings.size() + closings.size();
    }
};
