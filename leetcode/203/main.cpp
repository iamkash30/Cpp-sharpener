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
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return head;
        ListNode *tmp = new ListNode(-1);
        tmp->next = head;
        head = tmp;

        while (tmp->next != nullptr) {
            if (tmp->next->val == val) {
                tmp->next = tmp->next->next;
            }
            else {
                tmp = tmp->next;
            }
        }
        head = head->next;
        return head;
    }

    void printList(const ListNode* list) {
        while (list != nullptr) {
            cout << list->val << " ";
            list = list->next;
        }
        cout << endl;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    s.printList(head);
    ListNode* temp = s.removeElements(head, 6);
    s.printList(temp);
    return 0;
}
