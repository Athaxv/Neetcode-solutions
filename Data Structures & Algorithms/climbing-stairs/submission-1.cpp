class Solution {
public:
    int solve(int n, int i, vector<int>& memo){
        if (i == n) return 1;
        if (i > n) return 0;

        if (memo[i] != -1) return memo[i];

        int one = solve(n, i + 1, memo);
        int two = solve(n, i + 2, memo);

        return memo[i] = one + two;
    }
    int climbStairs(int n) {
        vector<int> memo(n, -1);
        return solve(n, 0, memo);
    }
};
