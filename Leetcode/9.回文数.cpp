/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文�?
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {

        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;
        int sum = 0;
        while (x > sum)
        {
            sum = sum * 10 + x % 10;
            x = x / 10;
        }
        return (x == sum) || (x == sum / 10);
    }
};
// @lc code=end
