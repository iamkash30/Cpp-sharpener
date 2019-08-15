#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#pragma pack(1)
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
private:
    ListNode* reverse(ListNode* curr, ListNode **headRef) {
        if (curr->next == nullptr)
        {
            *headRef = curr;
            return curr;
        }
        ListNode *prev = curr;
        curr = reverse(curr->next, headRef);
        curr->next = prev;
        return prev;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode *revList = nullptr;
        ListNode *headRef = nullptr;
        revList = reverse(head, &headRef);
        revList->next = nullptr;
        revList = headRef;
        return head;
    }
};

/**
 * @brief main
 * @return
 */
int main()
{
    int a = 10;
    cout << a++ << endl;
    int b = ++a;
    cout << b << endl;
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    s.reverseList(head);
    return 0;
}
