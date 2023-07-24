/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head)
    {
        // if (head == nullptr || head->next == nullptr)
        // {
        //     return head;
        // }
        // struct ListNode *rest = head->next->next; // rest指向当前节点的下下个节点
        // struct ListNode *newHead = head->next;    // 当前节点的下一个节点放到前面
        // newHead->next = head;                     // 将当前节点放到第二个上
        // head->next = swapPairs(rest);             // 当前节点的下一个节点继续使用递归完成交换
        // return newHead;
        struct ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        struct ListNode *temp = dummyNode; // 代表当前遍历到的节点，目标是交换temp的后两个节点
        while (temp->next != nullptr && temp->next->next != nullptr)
        {
            struct ListNode *node1 = temp->next;
            struct ListNode *node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return dummyNode->next;
    }
};
// @lc code=end
