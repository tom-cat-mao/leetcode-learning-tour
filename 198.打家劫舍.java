/*
 * @lc app=leetcode.cn id=198 lang=java
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
    public int rob(int[] nums) {
        int f0 = 0, f1 = 0;

        for (int x: nums) {
            int newF = Math.max(f1, f0 + x);
            f0 = f1;
            f1 = newF;
        }

        return f1;
    }
}
// @lc code=end

