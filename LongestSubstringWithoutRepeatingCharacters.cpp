/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int result = 0;
        int curLen = 0;
        int firstIndex = 0;
        for(int i = 0; i < s.length(); ++i){
            if(m.find(s[i]) != m.end() && firstIndex <= m[s[i]]){
                curLen = i - m[s[i]];
                firstIndex = m[s[i]] + 1;
            }
            else {
                ++curLen;
                if(curLen > result){
                    result = curLen;
                }
            }
            m[s[i]] = i;
        }
        return result;
    }
};
