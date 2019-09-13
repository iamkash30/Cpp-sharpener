#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *head;

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main()
{
    head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);
    Solution s;
    ListNode *node = new ListNode(5);
    cout << head << endl;
    cout << node << endl;

    return 0;
}
