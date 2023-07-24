/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode *removeElements(ListNode *head, int val)
    {
        // struct ListNode *dummyHead = new ListNode(0, head);
        // struct ListNode *temp = dummyHead;
        // while (temp->next != nullptr)
        // {
        //     if (temp->next->val == val)
        //     {
        //         temp->next = temp->next->next;
        //     }
        //     else
        //     {
        //         temp = temp->next;
        //     }
        // }
        // return dummyHead->next;
        }
};
// @lc code=end
