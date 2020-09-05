/*

Given a list of scores of different students, return the average score of each student's top five scores in the order of each student's id.

Each entry items[i] has items[i][0] the student's id, and items[i][1] the student's score.  The average score is calculated using integer division.

 

Example 1:

Input: [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
Output: [[1,87],[2,88]]
Explanation: 
The average of the student with id = 1 is 87.
The average of the student with id = 2 is 88.6. But with integer division their average converts to 88.

*/

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> returnVec;
        sort(items.begin(), items.end(), [](vector<int> a, vector<int> b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        unordered_map<int,vector<int>> scores;
        
        for (int i = 0; i < items.size(); ++i) {
            if (scores[items[i][0]].size() != 5) {
                scores[items[i][0]].push_back(items[i][1]);
            }
        }
        
        for (pair<int,vector<int>> score : scores) {
            returnVec.push_back(vector<int> {score.first, accumulate(score.second.begin(), score.second.end(), 0)/5});
        }
        
//         for(auto i : items) {
//             std::cout << i[0] << " : " << i[1] << std::endl;
//         }
        sort(returnVec.begin(), returnVec.end());
        return returnVec;
    }
};