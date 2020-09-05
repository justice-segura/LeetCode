/*

In a row of trees, the i-th tree produces fruit with type tree[i].

You start at any tree of your choice, then repeatedly perform the following steps:

Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?

 

Example 1:

Input: [1,2,1]
Output: 3
Explanation: We can collect [1,2,1].
Example 2:

Input: [0,1,2,2]
Output: 3
Explanation: We can collect [1,2,2].
If we started at the first tree, we would only collect [0, 1].
Example 3:

Input: [1,2,3,2,2]
Output: 4
Explanation: We can collect [2,3,2,2].
If we started at the first tree, we would only collect [1, 2].
Example 4:

Input: [3,3,3,1,2,1,1,2,3,3,4]
Output: 5
Explanation: We can collect [1,2,1,1,2].
If we started at the first tree or the eighth tree, we would only collect 4 fruits.

*/

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int right = 0;
        set<int> s;
        int ans = 0;
        int new_start=0;
        bool thing = true;
        
        for (int left = 0; left < tree.size(); ++left){
            s.insert(tree[left]);
            right = left+1;
            while (s.size() < 3 && right < tree.size()) {
                s.insert(tree[right++]);
                if (s.size() == 2 && thing){
                    new_start = right-1;
                    thing = false;
                }
            }
            std::cout << "left " << left << "   right" << right << std::endl;
            if (right >= tree.size() && s.size() != 3){
                ans = max(ans, right-left);
            }
            else {
                ans = max(ans, right-left-1);
            }
            if (s.size() == 1){
                return ans;
            }
            thing = true;
            left
            s.clear();
        }
        return ans;
    }
};