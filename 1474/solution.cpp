/*

Given the head of a linked list and two integers m and n. Traverse the linked list and remove some nodes in the following way:

Start with the head as the current node.
Keep the first m nodes starting with the current node.
Remove the next n nodes
Keep repeating steps 2 and 3 until you reach the end of the list.
Return the head of the modified list after removing the mentioned nodes.

*/




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* temp = head;
        while (head) {
            int mCount = 0;
            int nCount = 0;
            while (head && mCount < m-1) {
                ++mCount;
                head = head->next;
            }
            while (head && head->next && nCount < n) {
                ++nCount;
                head->next = head->next->next;
            }
            if (head)
                head = head->next;
        }
        return temp;
    }
};