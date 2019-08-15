//============================================================================
// Name        : isCircularLinkedList.cpp
// Author      : Aakash Chitroda
// Version     :
// Copyright   : Your copyright notice
// Description : Program to check if the given linked list has cycle or is
//				 circular linked list or not.
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class ListNode {

public:
	explicit ListNode(int x) :
			val(x), next(nullptr) {}
	~ListNode() {
		if (next)
			delete next;
	}

	int val;
	ListNode *next;
};

bool hasCycle(ListNode *head) {
	if (nullptr == head)
		return false;
	ListNode *fast = head->next;
	ListNode *slow = head;

	while ((nullptr != fast)
			&& (nullptr != fast->next)
			&& (nullptr != slow)) {
		if (fast == slow)
			return true;
		fast = fast->next->next;
		slow = slow->next;
	}
	return false;
}

void createSLL(ListNode **head, std::vector<int> &nodes)
{
    if (nodes.size() == 0)
        return;
    *head = new ListNode(nodes[0]);
    ListNode* tmp = *head;
    for (unsigned i = 1; i < nodes.size(); i++)
    {
        tmp->next = new ListNode(nodes[i]);
        tmp = tmp->next;
    }
}

int main(int argc, char **argv) {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = head;

	hasCycle(head) ? cout << "Yes\n" : cout << "No\n";

	return 0;
}
