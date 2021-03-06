/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int n = s.length();
    int l = p.length();
    vector<int> ans;
    vector<int> vs(26, 0);
    vector<int> vp(26, 0);
    for (char c : p) ++vp[c - 'a'];
    for (int i = 0; i < n; ++i) {
      if (i >= l) --vs[s[i - l] - 'a'];
      ++vs[s[i] - 'a'];
      if (vs == vp) ans.push_back(i + 1 - l);
    }
    return ans;
  }
};
// @lc code=end

