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
 #include <vector>
class Solution {
public:
    bool isPalindrome(ListNode *head)
    {
        if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode* temp = head;
        vector<int> a;
        while(temp != NULL){
            a.push_back(temp->val);
            temp = temp->next;
        }
        int n = a.size();
        for(int i=0;i<n/2;i++){
            if(a[i] != a[n-i-1]){
                return false;
            }
        }
        return true;
    }
};