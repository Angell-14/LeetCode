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
    ListNode* middleNode(ListNode* head) {
        ListNode* beg = head;
        ListNode* end = head;
        if(!head || head->next == nullptr) return head;

        while(beg != nullptr && beg->next != nullptr){
            beg = beg->next->next;
            end = end->next;
        }
        return end;
        
    }
};