/*
 * @lc app=leetcode.cn id=279 lang=java
 *
 * [279] 完全平方数
 */

// @lc code=start
import java.util.*;
class Solution {
    private static final int N = 10000;
    private static final int[] f = new int[N + 1];

    static {
        Arrays.fill(f, Integer.MAX_VALUE);
        f[0] = 0;
        
        for (int i = 1; i * i <= N; i++) {
            for (int j = i * i; j <= N; j++) {
                f[j] = Math.min(f[j], f[j - i * i] + 1);
            }
        }
    }

    public int numSquares(int n) {
        return f[n];
    }
}
// @lc code=end

