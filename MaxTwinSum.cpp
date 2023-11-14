#include <bits/stdc++.h>
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> arr;
        long long ans = 0;
        ListNode* temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int s = arr.size();
        for(int i=0;i<s/2;i++){
            ans += (arr[i] + arr[s-i-1]);
        }
        return ans;
    }
};