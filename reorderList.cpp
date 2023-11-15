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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return;
        }

        ListNode* middle = findMiddle(head);
        ListNode* reversedHalf = reverse(middle->next);
        middle->next = NULL;
        mergeLists(head,reversedHalf);
    }
private:
    ListNode* findMiddle(ListNode* node) {
        ListNode* slow = node;
        ListNode* fast = node->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* current = node;

        while (current) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        return prev;
    }
    void mergeLists(ListNode* list1, ListNode* list2) {
        while (list2) {
            ListNode* temp1 = list1->next;
            ListNode* temp2 = list2->next;
            list1->next = list2;
            list2->next = temp1;
            list1 = temp1;
            list2 = temp2;
        }
    }
};