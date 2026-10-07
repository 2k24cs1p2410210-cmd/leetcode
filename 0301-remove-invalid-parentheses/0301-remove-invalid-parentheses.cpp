class Solution {
public:
    unordered_set<string> ans;

    void dfs(string &s, int index, int left, int right, int balance, string curr) {

        if (index == s.size()) {
            if (left == 0 && right == 0 && balance == 0) {
                ans.insert(curr);
            }
            return;
        }

        char ch = s[index];

        // Remove current parenthesis
        if (ch == '(' && left > 0) {
            dfs(s, index + 1, left - 1, right, balance, curr);
        }

        if (ch == ')' && right > 0) {
            dfs(s, index + 1, left, right - 1, balance, curr);
        }

        // Keep current character
        if (ch != '(' && ch != ')') {
            dfs(s, index + 1, left, right, balance, curr + ch);
        }
        else if (ch == '(') {
            dfs(s, index + 1, left, right, balance + 1, curr + ch);
        }
        else if (ch == ')' && balance > 0) {
            dfs(s, index + 1, left, right, balance - 1, curr + ch);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int left = 0;
        int right = 0;

        for (char ch : s) {
            if (ch == '(') {
                left++;
            }
            else if (ch == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }

        string curr;
        dfs(s, 0, left, right, 0, curr);

        return vector<string>(ans.begin(), ans.end());
    }
};