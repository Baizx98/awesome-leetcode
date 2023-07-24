/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode *reverseList(ListNode *head)
    {
        // struct ListNode *prev = nullptr;
        // struct ListNode *curr = head;
        // while (curr)
        // {
        //     struct ListNode *next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = next;
        // }
        // return prev;
        // struct ListNode *temp = nullptr;
        // for (struct ListNode *x = head; x; x = x->next)
        // {
        //     temp = new ListNode(x->val, temp);
        // }
        // return temp;
        // if (head == nullptr || head->next == nullptr)
        // {
        //     return head;
        // }
        // ret = reverseList(head->next);
        // head->next->next = head;
        // head->next = nullptr;
        // return ret;
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        struct ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
// @lc code=end
