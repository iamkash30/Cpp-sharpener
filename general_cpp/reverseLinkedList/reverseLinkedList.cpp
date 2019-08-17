//============================================================================
// Name        : reverseLinkedList.cpp
// Author      : Aakash Chitroda
// Version     :
// Copyright   : Your copyright notice
// Description : Program to reverse a given linked list (In-place)
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class ListNode {

public:
	explicit ListNode(int x) :
			val(x), next(nullptr) {
	}
	~ListNode() {
		if (next)
			delete next;
	}

	int val;
	ListNode *next;
};

void createSLL(ListNode **head, std::vector<int> &nodes) {
	if (nodes.size() == 0)
		return;
	*head = new ListNode(nodes[0]);
	ListNode *tmp = *head;
	for (unsigned i = 1; i < nodes.size(); i++) {
		tmp->next = new ListNode(nodes[i]);
		tmp = tmp->next;
	}
}

void printSLL(ListNode *head) {
	ListNode *tmp = head;
	while (tmp) {
		std::cout << tmp->val << " ";
		tmp = tmp->next;
	}
	std::cout << '\n';
}

ListNode* reverseSLL(ListNode *head) {
	ListNode *prev = nullptr;
	while (head != nullptr) {
		ListNode *next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	head = prev;
	return head;
}

int main(int argc, char **argv) {
	vector<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);

	ListNode *head;

	createSLL(&head, list);
	printSLL(head);

	head = reverseSLL(head);
	printSLL(head);
	return 0;
}
