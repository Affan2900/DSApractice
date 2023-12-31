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
        ListNode* curr = head;
        int cnt = 0;
        while(curr != nullptr){
            cnt++;
            curr = curr->next;
        }
        ListNode* mid = head;
        int n = cnt/2;
        for(int i=0;i<n;i++){
            mid = mid->next;
        }
        return mid;
    }
};