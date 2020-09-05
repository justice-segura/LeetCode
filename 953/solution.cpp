/*

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).

*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> stuff(26,0);
        for (int i = 0; i < order.size(); ++i){
            stuff[order[i]-'a'] = i;
        }
        
        
        for (int i = 0; i < words.size()-1; ++i){
            int size = min(words[i].size(),words[i+1].size());
            for (int j = 0; j < size; ++j){
                if (stuff[words[i][j]-'a'] > stuff[words[i+1][j]-'a']){
                    return false;
                }
                else if (stuff[words[i][j]-'a'] < stuff[words[i+1][j]-'a']){
                    break;
                }
                if (j == size-1){
                    if (words[i].size() > words[i+1].size()){
                        return false;
                    }
                }
            }
        }
        
        return true;
        
    }
};

// "jqidl"
// 26 => [a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z]
//       [ , , ,3, , , , ,2,0, ,4, , , , ,1, , , , , , , , , ]