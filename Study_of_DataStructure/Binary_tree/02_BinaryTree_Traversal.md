# 二叉树的遍历 (Binary Tree Traversal)

------

## 1. 基本概念

二叉树的遍历是指按某种特定顺序访问树中的所有节点。

- **广度优先遍历 (BFS)**：层序遍历，体现“一圈一圈向外扩展”的逻辑。
- **深度优先遍历 (DFS)**：前序、中序、后序遍历，体现“先走到尽头，再回溯继续”的逻辑。

------

## 2. 层序遍历 (Level-Order Traversal)

层序遍历从顶部到底部逐层遍历，每一层按从左到右顺序访问节点。本质是**广度优先搜索 (BFS)**。

### 2.1 代码实现 (使用队列)

广度优先遍历通常借助 **队列 (Queue)** 来实现，遵循“先进先出”原则。

C++

```
#include <vector>
#include <queue>
using namespace std;

vector<int> levelOrder(TreeNode *root) {
    vector<int> res;
    if (root == nullptr) return res;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop(); 

        res.push_back(node->val); 

        // 逐层将子节点加入队列
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
    }
    return res;
}
```

### 2.2 复杂度分析

- **时间复杂度**：O(N)。每个节点访问一次。
- **空间复杂度**：O(N)。最差情况下，队列最多存储一层节点（约 N/2 个）。

------

## 3. 深度优先遍历 (DFS)

### 3.1 递归方式实现 (Recursive)

递归利用系统调用栈隐式处理回溯逻辑，代码最简洁。

C++

```
/* 前序：根 -> 左 -> 右 */
void preOrder(TreeNode *root, vector<int> &res) {
    if (root == nullptr) return;
    res.push_back(root->val);
    preOrder(root->left, res);
    preOrder(root->right, res);
}

/* 中序：左 -> 根 -> 右 */
void inOrder(TreeNode *root, vector<int> &res) {
    if (root == nullptr) return;
    inOrder(root->left, res);
    res.push_back(root->val);
    inOrder(root->right, res);
}

/* 后序：左 -> 右 -> 根 */
void postOrder(TreeNode *root, vector<int> &res) {
    if (root == nullptr) return;
    postOrder(root->left, res);
    postOrder(root->right, res);
    res.push_back(root->val);
}
```

### 3.2 迭代方式实现 (Iterative)

迭代法通过手动维护一个 **栈 (Stack)** 来模拟递归。

#### (1) 前序遍历迭代法

**逻辑**：根节点入栈 -> 弹出并访问 -> **先压右孩子，再压左孩子**（保证左孩子先出栈）。

C++

```
vector<int> preOrderIterative(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        res.push_back(node->val);
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return res;
}
```

#### (2) 中序遍历迭代法

**逻辑**：指针一直向左钻到底并压栈；走不动时弹出栈顶访问（根），然后转向右子树。

C++

```
vector<int> inOrderIterative(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
    return res;
}
```

#### (3) 后序遍历迭代法 (反转技巧)

**逻辑**：前序是“根-左-右”。我们改为“根-右-左”入栈，最后将结果数组整体反转，即得“左-右-根”。

C++

```
vector<int> postOrderIterative(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        res.push_back(node->val);
        if (node->left) st.push(node->left);
        if (node->right) st.push(node->right);
    }
    reverse(res.begin(), res.end());
    return res;
}
```

------

## 4. 复杂度分析汇总

- **时间复杂度**：均为 O(N)。所有节点访问一次。
- **空间复杂度**：均为 O(H)。H 为树的高度。
  - **最好情况（平衡树）**：O(log N)。
  - **最坏情况（退化为链表）**：O(N)。

------

## 5. 学习总结：如何克服抽象感？

1. **递归与迭代的关系**：递归是系统帮你管理栈，迭代是你自己手写栈。
2. **中序迭代的诀窍**：中序是“左-根-右”。当你一直往左钻的时候，栈就像记事本，帮你记下了回家的路。当你弹出栈顶时，代表你已经处理完了左边，现在该处理“根”，处理完根立刻去“右边”。
3. **手动模拟**：建议找一棵只有3个节点的树（A为根，B为左，C为右），对着代码一行行写出栈的变化。只要亲手画过一遍栈的入栈出栈，抽象感就会消失。