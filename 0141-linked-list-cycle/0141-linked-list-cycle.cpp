/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;

        if(!head) return false;
        while(temp1 != nullptr && temp1->next != nullptr){
            temp2 = temp2->next;
            temp1 = temp1->next->next;
            if(temp2 == temp1) return true;
        }
        return false;
    }
};