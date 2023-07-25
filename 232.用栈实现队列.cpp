/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;
// @lc code=start
class MyQueue
{
public:
    stack<int> in, out;
    MyQueue()
    {
    }

    void push(int x)
    {
        in.push(x);
    }

    int pop()
    {
        while (!in.empty())
        {
            int temp = in.top();
            in.pop();
            out.push(temp);
        }
        int value = out.top();
        out.pop();
        while (!out.empty())
        {
            int temp = out.top();
            out.pop();
            in.push(temp);
        }
        return value;
    }

    int peek()
    {
        while (!in.empty())
        {
            int temp = in.top();
            in.pop();
            out.push(temp);
        }
        int value = out.top();
        while (!out.empty())
        {
            int temp = out.top();
            out.pop();
            in.push(temp);
        }
        return value;
    }

    bool empty()
    {
        return in.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
