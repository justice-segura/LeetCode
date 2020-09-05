/*

Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.

*/

class Solution {
public:
    bool check(string s, int start, int end, int count){
        int left = start;
        int right = end;
        std::cout << s[left] << " : " << s[right] << std::endl;
        while (left < right){
            if (count >= 2){
                return false;
            }
            if (s[left] != s[right]){
                return check(s, left+1, right, count+1) || check(s, left, right-1, count+1);
            }
        ++left;
        --right;
        }
        return count < 2;
    }
    bool validPalindrome(string s) {
        return check(s, 0, s.size()-1, 0);
    }
    
    
    
    
};