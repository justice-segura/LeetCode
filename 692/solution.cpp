/*

Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.


*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> counts;
        vector<string> result;
        
        for(string w : words){
            counts[w]++;
        }  
        auto comp = [](auto a, auto b){
            return a.second==b.second ? a.first > b.first : a.second < b.second;
        };
        //vector<pair<string,int>> v(counts.begin(), counts.end());
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype (comp)> PQ(counts.begin(), counts.end(), comp); 
        
        // sort(v.begin(), v.end(), [](auto a, auto b){
        //     return a.second==b.second ? a.first < b.first : a.second > b.second;
        // });
        
        for(int j = 0; j < k; j++){
            result.push_back(PQ.top().first);
            PQ.pop();
        }
        return result;
    }
};