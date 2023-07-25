/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
using namespace std;
// @lc code=start
class MyStack
{
public:
    queue<int> q;
    int size = 0;
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
        size++;
    }

    int pop()
    {
        int count = size;
        while (count > 1)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
            count--;
        }
        int temp = q.front();
        q.pop();
        size--;
        return temp;
    }

    int top()
    {
        int count = size;
        while (count > 1)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
            count--;
        }
        int temp = q.front();
        q.pop();
        q.push(temp);
        return temp;
    }

    bool empty()
    {
        return size == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
