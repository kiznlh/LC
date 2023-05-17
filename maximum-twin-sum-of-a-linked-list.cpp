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

    // divide the linked list in half by using two pointer, one is travel 1 node, one is travel 2 nodes to get the position of the middle node;
    // x --> y --> z --> t --> nullptr ==>>>> z = middle node
    // then reverse the right half of the nodes 
    // calculate the max sum
    // this approach will change the linked list -> copy the linked list if needed
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int maxV = 0;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* nextNode;
        ListNode* prev = nullptr;
        while (slow){
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }
        while (prev){
            maxV = max(maxV, head->val + prev->val);
            head = head->next;
            prev = prev->next;
        }
        return maxV;
    }
};

int main(){
 
}