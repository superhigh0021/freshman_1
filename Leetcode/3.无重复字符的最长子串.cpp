/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子�?
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> t;
        int left=0,maxStr=0;
        for(int i=0;i!=s.size();++i){
            while(t.find(s[i])!=t.end()){
                t.erase(s[left++]);
            }
            maxStr=max(maxStr,i-left+1);
            t.insert(s[i]);
        }
        return maxStr;
    }
};
// @lc code=end
