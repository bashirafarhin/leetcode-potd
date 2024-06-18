class Solution {
public:
    vector<int> solve(string exp, int s, int e) {
        if (e - s == 1) {
            int n = (exp[s] - '0') * 10 + (exp[e] - '0');
            return {n};
        }
        if (e == s) {
            int n = exp[s] - '0';
            return {n};
        }

        vector<int> ans;
        for (int j = s; j <= e; j++) {
            if (exp[j] == '+' || exp[j] == '-' || exp[j] == '*') {
                vector<int> l = solve(exp, s, j - 1);
                vector<int> r = solve(exp, j + 1, e);

                for (int n1 : l) {
                    for (int n2 : r) {
                        if (exp[j] == '+') {
                            ans.push_back(n1 + n2);
                        } else if (exp[j] == '-') {
                            ans.push_back(n1 - n2);
                        } else {
                            ans.push_back(n1 * n2);
                        }
                    }
                }
            }
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.length();
        return solve(expression, 0, n - 1);
    }
};