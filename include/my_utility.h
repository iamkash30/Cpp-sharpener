#ifndef MY_UTILITY_H
#define MY_UTILITY_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>

struct ListNode
{
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(NULL){}
    ~ListNode()
    {
        if (next)
            delete next;
    }
};

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

void printSLL(ListNode *head)
{
    ListNode *tmp = head;
    while (tmp)
    {
        std::cout << tmp->val << " ";
        tmp = tmp->next;
    }
    std::cout << '\n';
}

class TreeNode
{
  public:
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void createBT(TreeNode **root, std::vector<std::string> nodes)
{
    if (nodes.size() == 0)
        return;
    std::queue<TreeNode *> q;
    *root = new TreeNode(std::stoi(nodes[0]));
    q.push(*root);
    for (unsigned i = 1; i < nodes.size(); i++)
    {
        if (q.empty())
        {
            std::cout << "Exception.. not able to create binary tree!\n";
            break;
        }
        auto top = q.front();
        q.pop();
        if (nodes[i] != "null")
        {
            top->left = new TreeNode(std::stoi(nodes[i]));
            q.push(top->left);
        }
        if (i + 1 < nodes.size() && nodes[i + 1] != "null")
        {
            top->right = new TreeNode(std::stoi(nodes[i + 1]));
            q.push(top->right);
            i++;
        }
    }
}

void printInOrder(TreeNode *root)
{
    if (!root)
        return;
    printInOrder(root->left);
    std::cout << root->val << " ";
    printInOrder(root->right);
}

#endif // MY_UTILITY_H
