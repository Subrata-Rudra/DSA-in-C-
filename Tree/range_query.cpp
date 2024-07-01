#include <bits/stdc++.h>
using namespace std;

struct maxTreeNode
{
    int maxx;
    int low;
    int high;
    maxTreeNode *left;
    maxTreeNode *right;
    maxTreeNode()
    {
        maxx = INT_MIN;
        low = INT_MIN;
        high = INT_MIN;
        left = NULL;
        right = NULL;
    }
};

maxTreeNode *buildMaxTree(vector<int> &v, int start, int end)
{
    if (start == end)
    {
        maxTreeNode *node = new maxTreeNode();
        node->maxx = v[start];
        return node;
    }
    int mid = start + (end - start) / 2;
    maxTreeNode *node = new maxTreeNode();
    node->left = buildMaxTree(v, start, mid);
    node->right = buildMaxTree(v, mid + 1, end);
    node->maxx = max(node->left->maxx, node->right->maxx);
    node->low = start;
    node->high = end;
    return node;
}

void levelOrderTraversal(map<int, vector<int>> &res, maxTreeNode *node, int level)
{
    res[level].push_back(node->maxx);
    if (node->left)
    {
        levelOrderTraversal(res, node->left, level + 1);
    }
    if (node->right)
    {
        levelOrderTraversal(res, node->right, level + 1);
    }
}

int rangeQuery(maxTreeNode *node, int start, int end)
{
    if (node->low <= start && node->high >= end) // Complete Overlap
    {
        return node->maxx;
    }
    if (node->low > end || node->high < start) // No Overlap
    {
        return INT_MIN;
    }
    // Partial Overlap
    int leftMax = rangeQuery(node->left, start, end);
    int rightMax = rangeQuery(node->right, start, end);
    return max(leftMax, rightMax);
}

int main()
{
    vector<int> v;
    cout << "----------------------------------\n";
    cout << "|      Range Query on Array      |\n";
    cout << "----------------------------------\n";
    int n;
    cout << "Enter the size of the array:\n";
    cin >> n;
    cout << "Now, enter the elements of the array:\n";
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    int start, end;
    cout << "Now enter the range(use 0 based indexing):\n";
    cin >> start >> end;
    maxTreeNode *root = buildMaxTree(v, start, end);
    map<int, vector<int>> res;
    levelOrderTraversal(res, root, 0);
    cout << "--------------------------------------------------\n";
    cout << "---------------------TREE START-------------------\n";
    cout << "--------------------------------------------------\n";
    int ind = 0;
    for (auto it : res)
    {
        cout << "Level " << ind << " --> ";
        for (int j = 0; j < it.second.size(); j++)
        {
            cout << it.second[j] << " ";
        }
        cout << endl;
        cout << "--------------------------------------------------\n";
        ind++;
    }
    cout << "----------------------TREE END--------------------\n";
    cout << "--------------------------------------------------\n";
    int maximum = root->maxx;
    cout << "The MAXIMUM of the array inside the range of " << start << " and " << end << " is: " << maximum << endl;
    return 0;
}