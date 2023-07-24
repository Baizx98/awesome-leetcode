/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
#include <unordered_map>
using namespace std;
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // unordered_map<ListNode *, int> visited;
        // while (head != nullptr)
        // {
        //     if (visited.count(head))
        //     {
        //         return head;
        //     }
        //     visited.insert({head, 1});
        //     head = head->next;
        // }
        // return nullptr;
        struct ListNode *f = head, *s = head;
        if (head == nullptr)
            return nullptr;

        while (true)
        {
            if (f == nullptr || f->next == nullptr)
            {
                return nullptr;
            }
            f = f->next->next;
            s = s->next;
            if (f == s)
            {
                break;
            }
        }
        f = head;
        while (f != s)
        {
            f = f->next;
            s = s->next;
        }
        return f;
    }
};
// @lc code=end
