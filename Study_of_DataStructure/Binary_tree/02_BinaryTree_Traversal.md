# 二叉树的遍历 (Binary Tree Traversal)

## 1. 基本概念

二叉树是一种非线性数据结构，遍历树需要借助搜索算法来实现。

- **广度优先遍历 (BFS)**：层序遍历，体现“一圈一圈向外扩展”的逻辑。
- **深度优先遍历 (DFS)**：前序、中序、后序遍历，体现“先走到尽头，再回溯继续”的逻辑。

------

## 2. 层序遍历 

层序遍历从顶部到底部逐层遍历，每一层按从左到右顺序访问节点。

### 2.1 代码实现 (使用队列)

广度优先遍历通常借助**队列 (Queue)**来实现，遵循“先进先出”原则。

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

- **时间复杂度**：$O(N)$。每个节点访问一次。
- **空间复杂度**：$O(N)$。最差情况下（满二叉树），队列最多同时存储一层节点，约为 $N/2$。

------

## 3. 深度优先遍历 (DFS)

### 3.1 递归方式实现 (Recursive)

递归利用系统调用栈隐式处理回溯逻辑。

C++

```
/* 前序遍历：根 -> 左 -> 右 */
void preOrder(TreeNode *root, vector<int> &res) {
    if (root == nullptr) return; 
    res.push_back(root->val);    
    preOrder(root->left, res);        
    preOrder(root->right, res);       
}

/* 中序遍历：左 -> 根 -> 右 */
void inOrder(TreeNode *root, vector<int> &res) {
    if (root == nullptr) return;
    inOrder(root->left, res);         
    res.push_back(root->val);    
    inOrder(root->right, res);       
}

/* 后序遍历：左 -> 右 -> 根 */
void postOrder(TreeNode *root, vector<int> &res) {
    if (root == nullptr) return;
    postOrder(root->left, res);       
    postOrder(root->right, res);      
    res.push_back(root->val);    
}
```

### 3.2 迭代方式实现 (Iterative)

迭代法通过显式维护一个**栈 (Stack)**来模拟递归过程，避免过深的递归导致栈溢出。

#### (1) 前序遍历：根 -> 左 -> 右

利用栈“后进先出”特性，先压入右孩子，再压入左孩子。

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

#### (2) 中序遍历：左 -> 根 -> 右

指针一直向左走到底并入栈，走不动时弹出栈顶访问，然后转向右子树。

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

#### (3) 后序遍历：左 -> 右 -> 根 (双栈法/反转法)

**逻辑**：前序遍历是“根-左-右”，将其改为“根-右-左”，最后将结果反转即可得到“左-右-根”。

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
        res.push_back(node->val); // 顺序：根 -> 右 -> 左
        if (node->left) st.push(node->left);
        if (node->right) st.push(node->right);
    }
    reverse(res.begin(), res.end()); // 反转后：左 -> 右 -> 根
    return res;
}
```

### 3.3 复杂度分析

- **时间复杂度**：$O(N)$。所有节点访问一次。
- **空间复杂度**：$O(H)$。$H$ 为树的高度。最坏情况（退化为链表）为 $O(N)$，最好情况（平衡树）为 $O(\log N)$。