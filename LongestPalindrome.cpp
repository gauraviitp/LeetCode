/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int startIndex = 0;
        for(int i = 0; i < s.length(); ++i){
            if(i+1 < s.size() && s[i] == s[i+1]){
                int len = 2, j = 1;
                if(len > maxLen){
                        maxLen = len;
                        startIndex = i;
                    }
                while(i-j >= 0 && i+1+j < s.length() && s[i-j] == s[i+1+j]){
                    len = 2 + j*2;
                    if(len > maxLen){
                        maxLen = len;
                        startIndex = i-j;
                    }
                    ++j; 
                }
            }
            {
                int len = 1, j = 1;
                if(len > maxLen){
                        maxLen = len;
                        startIndex = i;
                    }
                while(i-j >= 0 && i+j < s.length() && s[i-j] == s[i+j]){
                    len = 1 + j*2;
                    if(len > maxLen){
                        maxLen = len;
                        startIndex = i-j;
                    }
                    ++j;
                }
            }
        }
        //cout << startIndex << ' ' << maxLen << '\n';
        return s.substr(startIndex, maxLen);
    }
};
