#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
struct Node
{
    int val;
    Node *left, *right;
    Node(int v)
    {
        val = v;
        left = right = nullptr;
    }
};
//dfs 遍历
//记录路径
vector<int> step;

//最终答案
vector<vector<int>> ret;
void dfs(Node *r, int target, int curtotal)
{
    if (r)
    {
        step.push_back(r->val);
        //叶并且判断条件
        if (r->left == nullptr && r->right == nullptr && (curtotal + r->val) == target)
        {
            ret.push_back(step);
            step.pop_back();
            return;
        }
        dfs(r->left, target, curtotal + r->val);
        dfs(r->right, target, curtotal + r->val);
        step.pop_back();
    }
}
void targetSum(vector<int> tree, int target)
{
    //build tree
    queue<Node *> q;
    int i = 0;
    Node *root = new Node(tree[i++]);
    q.push(root);
    int nodecnt = tree.size();
    while (!q.empty())
    {
        int ln = q.size();
        for (int j = 0; j < ln; j++)
        {
            Node *curNode = q.front();
            q.pop();
            if (i < nodecnt)
            {
                int lf = tree[i++];
                if (lf != -1)
                {
                    curNode->left = new Node(lf);
                    q.push(curNode->left);
                }
            }
            if (i < nodecnt)
            {
                int rg = tree[i++];
                if (rg != -1)
                {
                    curNode->right = new Node(rg);
                    q.push(curNode->right);
                }
            }
        }
    }
    //
    dfs(root, target, 0);

    //
    for (auto &r : ret)
    {
        for (auto &num : r)
        {
            cout << num << "-";
        }
        cout << endl;
    }
}

int main()
{
    //为了方便null用-1代替，默认结点没有-1,懒得分解字符串了
    vector<int> vec{5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1};
    targetSum(vec, 22);
    return 0;
}
