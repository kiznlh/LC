#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        ListNode* ans = head;
        ListNode* prev = nullptr;
        int count = 0;
        while (cur && cur->next){
            
            ListNode* first = cur;
            ListNode* second = cur->next;
            first->next = second->next;
            second->next = first;
            if (prev){
                prev->next = second;
            }
            if (count == 0){
                ans = second;
                ++count;
            }
            prev = first;
            cur = first->next;
        }
        return ans;
    }
};
    