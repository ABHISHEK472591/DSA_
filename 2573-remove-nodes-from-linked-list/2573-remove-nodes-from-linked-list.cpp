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

    ListNode*reverselist(ListNode*head) {
        ListNode*prev = NULL;
        ListNode*curr = head;

        while(curr) {
            ListNode*nn = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nn;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverselist(head);
        
        if (!head || !head->next) {
            return head;  // Return if the list is empty or has only one element
        }
        
        ListNode*curr2 = head;
        ListNode*nn2 = head->next;

        while(curr2->next) {
            if(curr2->val > nn2->val) {
                curr2->next = nn2->next;
               
                nn2 = curr2->next;
            } else {
                curr2= nn2;
                nn2 = nn2->next;
            }
        }
        return reverselist(head);
    }
};