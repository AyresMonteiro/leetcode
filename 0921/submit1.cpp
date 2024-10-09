// I ignored the order of elements and forgot to pop
// valid strings out.

// This solution didn't pass.

class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s == "") return 0;

        stack<char> openings;
        stack<char> closings;

        for (char c : s) {
            switch(c) {
                case '(':
                    openings.push(c);
                    continue;
                case ')':
                    closings.push(c);
                    continue;
            }
        }

        while(!openings.empty() && !closings.empty()) {
            openings.pop();
            closings.pop();
        }

        return openings.size() + closings.size();
    }
};
