/*

A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        vector<int> m(26,-1);
        
        // stores all indicies in map
        for(int i = 0; i < S.size(); i++){
            m[S[i]-'a'] = i;
        }
        
        int last = m[S[0]-'a'];
        int sum = 0;
        
        for(int j = 0; j < S.size(); j++){
            int currLast = m[S[j]-'a'];
            last = max(currLast, last);
            
            if(j == last){
                ans.push_back(j-sum+1);
                sum = j + 1;
            } 
        }
        return ans;
    }
};