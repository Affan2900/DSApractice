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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head = nullptr; // Initialize head to nullptr
        ListNode* curr = nullptr;

        // Choose the initial node among list1 and list2
        if (list1 != nullptr && (list2 == nullptr || list1->val <= list2->val)) {
            head = list1;
            list1 = list1->next;
        } else if (list2 != nullptr) {
            head = list2;
            list2 = list2->next;
        }

        curr = head;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
            } else {
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            }
        }

        // Append any remaining nodes from list1 and list2
        if (list1 != nullptr) {
            curr->next = list1;
        }
        if (list2 != nullptr) {
            curr->next = list2;
        }

        return head;
    }
};