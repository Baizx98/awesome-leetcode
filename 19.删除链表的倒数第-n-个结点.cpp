/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        struct ListNode *dummyNode = new ListNode(0, head);
        struct ListNode *front = head;
        struct ListNode *behind = dummyNode;
        for (int i = 0; i < n; i++)
        {
            front = front->next;
        }
        while (front != nullptr)
        {
            front = front->next;
            behind = behind->next;
        }
        // 此时behind就是倒数第N个节点的前驱节点
        behind->next = behind->next->next;
        return dummyNode->next;
    }
};
// @lc code=end
