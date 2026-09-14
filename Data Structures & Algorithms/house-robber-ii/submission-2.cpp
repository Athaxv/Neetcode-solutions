class Solution {
public:
    int solve(vector<int>& nums, int i, int n, vector<int>& memo){
        if (i >= n) return 0;

        if (memo[i] != -1) return memo[i];

        int steal = nums[i] + solve(nums, i + 2, n, memo);
        int jump = solve(nums, i + 1, n, memo);

        return memo[i] = max(steal, jump);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1){
            return nums[0];
        }
        vector<int> memo1(n, -1);
        vector<int> memo2(n, -1);

        return max(solve(nums, 0, n - 1, memo1), solve(nums, 1, n, memo2));
    }
};
