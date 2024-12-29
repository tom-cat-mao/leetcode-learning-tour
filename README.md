# leetcode-learning-tour

This is a note for my leetcoding learning tour.
I will add some algorithm to this file.

## KMP algorithm (子串搜索算法)

### 思路
当一次比对失败时，利用已经匹配的那部分信息，将模式串尽可能多地移动到一个合适的位置，使得下一次比对可以从上一次匹配失败的那个位置开始继续进行。

### Example
*s*: "ABCABCABE" *p*: "ABCABE"
- 从零开始查找，到第六位时匹配失败。
- 如果从第五位再开始第二轮查找，则后续字符串长度不够，无法完成查找，得出错误结果。
- 则需要注意前后缀
- 注意到前五个组成的字符串具有相同的前后缀**AB**
- 即求已匹配的部分串中最长的相同前后缀长度为**next**, 第一对不匹配的字符**index**为**i**.
- 下一轮从**i**，开始比对，但将匹配字符串移至**i - next**处。

### Pesudocode
```latex
\(\text{Naive_Next}(next, P):\)

    \(next[0]\leftarrow-1\)

    \(k\leftarrow-1\)

    \(j\leftarrow0\)

    \(\text{WHILE }j\lt \text{Len}(P) \text{ DO}\)

        \(\text{IF }k=-1\text{ OR }P[j]=P[k] \text{ THEN}\)

            \(k\leftarrow k+1\)

            \(j\leftarrow j+1\)

            \(next[j]\leftarrow k\)

        \(\text{ELSE}\)

            \(k\leftarrow next[k]\)

```

## 单调栈

### 例题为 [42.接水](./42.接雨水.cpp)

### 特点
栈中的元素始终保持单调有序。通常有两种单调栈，分别是单调递增栈和单调递减栈。

### 应用场景
在数组中寻找元素左侧或右侧的最大或最小值

### 框架
```java
        deque.push(0);
        for(int i=1;i<lens;i++){
                //循环比较，直到遇到当前元素小于栈顶的元素情况，跳出循环
                //单调递减栈，这里是小于，即nums[i]<nums[deque.peek()]
                //因为while循环里面已经做条件判断了
                while(!deque.isEmpty()&&nums[i]>nums[deque.peek()]){
                    //主要逻辑
                    ............
                    ...........
                    //弹出栈顶元素
                    deque.pop();
                }
                stack.push(i);

        }
```

## 单调队列

### 例题为 [239.滑动窗口最大值](./239.滑动窗口最大值.cpp)

### 特点
单调递减或者单调递增的队列。队列中的元素只能在队尾入队、从队首或者队尾出队。

### 本质
单调队列的基本实现就是维护一个双向队列，只有当一个元素是当前最值、或者可能成为最值时才保留，否则出队。

### 代码表示
```cpp
vector<int> v;//依次加入的成员
deque dq;//双向队列、存储下标
int size = v.size();
for( int i = 0;i < size;++i)
{
    while(!dq.empty() && i - dq.front() >= k )
        dq.pop_front();// 超年限的成员、必须让位

    while(!dq.empty() && v[dq.back()] < v[i])
        dq.pop_back();// 老成员能力比新成员小则直接出局

    dq.push_back(i);// 新成员一定入队
}
```

## 滑动窗口

### 例题为： [3.无重复字符的最长字符串](./3.无重复字符的最长子串.cpp), [438.找到字符串中所有字母异位词](./438.找到字符串中所有字母异位词.cpp)

### 模板
```cpp
//外层循环扩展右边界，内层循环扩展左边界
for (int l = 0, r = 0 ; r < n ; r++) {
	//当前考虑的元素
	while (l <= r && check()) {//区间[left,right]不符合题意
        //扩展左边界
    }
    //区间[left,right]符合题意，统计相关信息
}
```

##  Sparse Table(ST/稀疏表)

### 特点
需要进行预处理，在O(1)时间内处理任意区间内的结果，预处理时间为O(nlogn)

### 思路
将数组或字符串预处理，分成以2为底数的长度的子串，再对子串进行合并，处理，类似于merge sort 但需要进行预处理

适用性
适用于RMQ问题和RGQ问题
- RMQ：Range Minimum Query
- 区间最大最小值问题
- RGQ： Range GCD Query
- 区间最大公约数问题

### Example
求数组中以**k**为长度的子数组中每个最大的值。

#### 思路
对数组长度求以2为底数的对数值，即log<sub>2</sub>(length) = k. 得到数组内最大长度的子数组，可能出现重复问题，但不影响计算结果。如下图所示

![Alt Text](./images/ST.png)

#### 示例代码
```cpp
#include <bis/stdc++.h>
using namespace std;

const int MAX_H = 100005;
const int LOG = 17;
int a[MAX_N];
int m[MAX_N][LOG];
int bin_log[MAX_H];

int query(int L, int R) {
    int length = R - L + 1;
    int k = bin_log[length]; // something like a matrix
    return min(m[L][k], m[R - (1 << k) + 1][k]);
}

int main() {
    // 1) read input
    int n;
    cin >> n;
    bin_log[1] = 0;
    for (int i = 2; i < n; i++) {
        bin_log[i] = bin_log[i / 2] + 1;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[i][0] = a[i];
    }

    // 2) preprocessijng, O(N*log(N))
    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i + (1 << k) - 1 < n; i++) {
            m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]); // find the minimue number in the subarray, each subarray is devided by two
        }
    }

    // 3) answer queries
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int L, R;
        cin >> L >> R;
        cout << query(L, R) << "\n";
    }
}
```
[详细讲解](https://youtu.be/0jWeUdxrGm4?si=SW8AJGbjruhCvw7c)

## BitWise Operation

the ***&, |, AND ^*** operator

### check if the bit is 1 or 0

```cpp
for (int i = 0; (1 << i) <= n; i++) {
    if (n & (1 << i)) {
        cout << "1";
    } else {
        cout << "0";
    }
}
```

[详细讲解](https://youtu.be/xXKL9YBWgCY?si=nSjfuZOPxzLR9uiY)

## CPP二分查函数

### 例题 [240.搜索二维矩阵 II](./240.搜索二维矩阵-ii.cpp)

#### lower_bound(begin, end, num)
从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
#### upper_bound(begin, end, num)
从数组的begin位置到end-1位置二分查找第一个大于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。

## 合并两个链表

### 例题 [23.合并K个升序链表](./23.合并-k-个升序链表.cpp)

#### 例
a,b链表长度均为n，如何在**O(n)**的时间代价以及**O(1)**的空间代价完成合并

#### 宗旨：原地调整链表元素的next指针完成合并

#### 过程

- 首先用***head***保存合并之后的头部
- 指针***tail***记录下一个插入位置的前一个位置，以及两个指针***aPtr***,***bPtr***记录***a***,***b***未合并部分的第一位。
- 当***aPtr***和***bPtr***都不为空时，取***value***属性较小的合并；如果***aPtr***为空，则把整个***bPtr***以及后面的元素全部合并；***bPtr***为空时同理。
- 合并时，应先调整***tail***的***next***属性，再后移***tail***和***Ptr***（***aPtr***或者***bPtr***）。***tail***和***Ptr***不存在先后顺序

#### 例
```cpp
ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
    if ((!a) || (!b)) return a ? a : b;
    ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
    while (aPtr && bPtr) {
        if (aPtr->val < bPtr->val) {
            tail->next = aPtr; aPtr = aPtr->next;
        } else {
            tail->next = bPtr; bPtr = bPtr->next;
        }
        tail = tail->next;
    }
    tail->next = (aPtr ? aPtr : bPtr);
    return head.next;
}
```

## Judge if a BST is Symmetric

### 例题：[101.对称二叉树](./101.对称二叉树.cpp)

#### 思路
通过比较树的左子树和右子树来实现，若左子树和右子树是对称的，则整个二叉树是对称的。

#### 伪代码
```
function isSymmetric(root):
    if root is null:
        return true
    else:
        return isMirror(root.left, root.right)

function isMirror(left, right):
    if left is null and right is null:
        return true
    if left is null or right is null:
        return false

    return (left.val == right.val) and
           isMirror(left.left, right.right) and
           isMirror(left.right, right.left)
```

## 遍历二叉树，但每层分开存储

### 中序遍历二叉树得到的数组是递增的

### 例题 [102.二叉树的遍历](./102.二叉树的层序遍历.cpp)

```cpp
// DFS
class Solution {
private:
    vector<vector<int>> ans;
public:
    void dfs(TreeNode* root, int depth) {
        if (!root) return;
        if (depth >= ans.size()) ans.push_back({root->val});
        else ans[depth].push_back(root->val);
        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
```

```cpp
// BFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> layer;
            while (n) {
                auto node = q.front(); q.pop(); n--;
                layer.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(layer);
        }
        return ans;
    }
};
```

## 检验二叉树是否正确

### 例题 [98.验证二叉搜索树](./98.验证二叉搜索树.cpp)

#### 思路
树中的节点是否正确，由上下限决定。

#### 方案一，递归
```cpp
class Solution {
public:
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
            return false;
        }
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
```

#### 方案二，中序遍历

##### 中序遍历二叉树得到的数组是递增的

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        long long inorder = (long long)INT_MIN - 1;

        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root -> left;
            }
            root = stack.top();
            stack.pop();
            // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
            if (root -> val <= inorder) {
                return false;
            }
            inorder = root -> val;
            root = root -> right;
        }
        return true;
    }
};
```

## 二叉树中序遍历（迭代算法）模板

### 模板
```cpp
while (!stack.empty() || root != nullptr) {
    while (root != nullptr) {
        stack.push(root);
        root = root -> left;
    }

    root = stack.top();
    stack.pop();

    // 判断条件或其他要求

    root = root -> right;
}
```

### 例题 [230.二叉搜索树中第K小的元素](./230.二叉搜索树中第-k-小的元素.cpp)

## 二叉树展开为链表

### 例题 [114.二叉树展开为链表](./114.二叉树展开为链表.cpp)

#### 作法一（非常聪明的做法）
```java
class Solution {
    public void flatten(TreeNode root) {
        while (root != null) {
            TreeNode move = root.left;
            //找到左子树的最右节点，即左子树最接近root的节点
            while (move != null && move.right != null) {
                move = move.right;
            }

            //将root的右子树接到左子树的最右节点上
            if (move != null) {
                move.right = root.right;
                root.right = root.left;
                root.left = null;
            }
            root = root.right;
        }
    }
}
```

#### 做法二（前序遍历）

```cpp
class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> l;
        preorderTraversal(root, l);
        int n = l.size();
        for (int i = 1; i < n; i++) {
            TreeNode *prev = l.at(i - 1), *curr = l.at(i);
            prev->left = nullptr;
            prev->right = curr;
        }
    }

    void preorderTraversal(TreeNode* root, vector<TreeNode*> &l) {
        if (root != NULL) {
            l.push_back(root);
            preorderTraversal(root->left, l);
            preorderTraversal(root->right, l);
        }
    }
};
```

## 从前序与中序遍历构造二叉树

### 例题 [105.从前序与中序遍历构造二叉树](./105.从前序与中序遍历序列构造二叉树.cpp)

#### 思路
中序遍历得到为[根节点, [左子树的前序遍历结果], [右子树的前序遍历结果]]

前序遍历得到为[[左子树的中序遍历结果], 根节点, [右子树的中序遍历结果]]

在中序遍历中**定位**到根节点。

同一子树的前序和中序长度是相同的，所以定位后可以**确定左右子树中节点的数目**。

由此可得一个巧妙的算法

#### 实例代码

```cpp
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        auto dfs = [](auto&& dfs, auto&& lP, auto&& lI, auto&& rI) {
            if (lI == rI) return (TreeNode*)nullptr;
            auto loc = find(lI, rI, *lP);
            return new TreeNode(*lP, dfs(dfs, lP + 1, lI, loc),
                                     dfs(dfs, lP + (loc - lI) + 1, loc + 1, rI));
        };
        return dfs(dfs, preorder.cbegin(), inorder.cbegin(), inorder.cend());
    }
};
```

## 二叉树的最近公共祖先

### 例题 [236.二叉树的最近公共祖先](./236.二叉树的最近公共祖先.cpp)

#### 思路

![Alt Text](./images/problem-168.png)

## Topological sorting（拓补排序）

### [Example](./207.课程表.cpp)

### mindset

Order the vertices of a directed acyclic graph(DAG) in such a way that for evey directed edge *u -> v*, vertex *u* comes before vertex *v* in the ordering.

### Pseudocode

#### DFS

```
function DFS(node):
    visited[node] = true
    for each neighbor of node:
        if not visited[neighbor]:
            DFS(neighbor)
    stack.push(node)

function topologicalSort():
    stack = empty stack
    visited = array of boolean values initialized to false, size n (number of nodes)

    for each node from 0 to n-1:
        if not visited[node]:
            DFS(node)

    return reverse(stack)

// Example usage:
n = number of nodes
adjList = adjacency list representation of the graph

topologicalOrder = topologicalSort()
print(topologicalOrder)
```

#### BFS
```
function topologicalSortBFS(adjList, inDegree):
    queue = empty queue
    topoOrder = empty list

    // Initialize the queue with all nodes that have an in-degree of 0
    for each node from 0 to n-1:
        if inDegree[node] == 0:
            enqueue(queue, node)

    // Process the queue until it is empty
    while not isEmpty(queue):
        currentNode = dequeue(queue)
        topoOrder.append(currentNode)

        for each neighbor of currentNode:
            inDegree[neighbor] -= 1
            if inDegree[neighbor] == 0:
                enqueue(queue, neighbor)

    // If the length of topoOrder is n (number of nodes), a topological sort exists
    return topoOrder

// Example usage:
n = number of nodes
adjList = adjacency list representation of the graph
inDegree = array of in-degrees initialized to 0, size n

// Calculate in-degrees for each node
for each node from 0 to n-1:
    for each neighbor in adjList[node]:
        inDegree[neighbor] += 1

topologicalOrder = topologicalSortBFS(adjList, inDegree) print(topologicalOrder)
```

## Get all the subset from a set of array

### mindset

- There are \(`2^n`\) options in the result include empty.
- Go through each option with bitwise operation to judge if the element should be put into the subset

### Pseudocode
```
function generateSubsets(arr):
    n = length(arr)
    result = new empty list

    # Loop through all numbers from 0 to 2^n - 1
    for i from 0 to 2^n - 1:
        currentSubset = new empty list
        for j from 0 to n-1:
            if (i & (1 << j)) != 0:
                append arr[j] to currentSubset
        append currentSubset to result

    return result
```

### [Example](./78.子集.cpp)


## Dynamic Programming

### [Example](./39.组合总和.cpp)

### [MindSet](./note-from-chat/组合总和算法.txt)

### Example Code

```cpp
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // 创建动态数组 dp，用于存储所有可能的组合
    vector<vector<vector<int>>> dp(target + 1);

    // 初始化 dp[0]，表示目标和为 0 的初始情况
    dp[0] = {{}};

    for (int i = 0; i < candidates.size(); i++) {
        for (int j = candidates[i]; j <= target; j++) {
            for (auto& group : dp[j - candidates[i]]) {
                vector<int> newGroup = group;
                // 复制当前组合
                newGroup.push_back(candidates[i]);
                // 添加新的候选数
                dp[j].push_back(newGroup);
            }
        }
    }

    return dp[target];
}
```

## Backtracking（回溯）

### [讲解](https://www.bilibili.com/video/BV1mG4y1A7Gu)

### 子集型

### Example [78.子集](./78.子集.cpp)  [131.分割回文串](./131.分割回文串.cpp)

#### 方法一

#### Consider Input

##### Mindset

1. 当前操作？枚举第 **i** 个数选/不选
2. 子问题？从下标 **>= i** 的数字中构造子集
3. 下一个子问题？从下标 **>= i + 1** 的数字中构造子集

dfs(i) -> dfs(i + 1)


```python
# problem 78
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        auns = []
        path = []
        n = len(nums)
        def dfs(i):
            // 判断是否正确，正确则插入答案
            if i == n:
                ans.append(path.copy())
                return

            // 忽略当前位置
            dfs(i + 1)

            // 考虑当前位置
            path.append(nums[i])
            dfs(i + 1)
            path.pop

        dfs(0)
        return ans
```

```cpp
// problem 131
class Solution {

    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }

        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> path;

        // start 表示当前这段回文子串的开始位置
        auto dfs = [&](auto&& dfs, int i, int start) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }

            // 不选 i 和 i+1 之间的逗号（i=n-1 时一定要选）
            if (i < n - 1) {
                dfs(dfs, i + 1, start);
            }



            // 选 i 和 i+1 之间的逗号（把 s[i] 作为子串的最后一个字符）
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                dfs(dfs, i + 1, i + 1); // 下一个子串从 i+1 开始
                path.pop_back(); // 恢复现场
            }
        };
        dfs(dfs, 0, 0);
        return ans;
    }
};
```

### 方法二

#### Consider Output

#### MindSet

1. 当前操作？ 枚举一个下标 **j >= i** 的数字，加入path
2. 子问题？从下标 **>=i** 的数字中构造子集
3. 下一个子问题？从下标 **>= j + 1** 的数字中构造子集

```
dfs(i) -> dfs(i + 1)
       -> dfs(i + 2)
       ...
       -> dfs(n)
```

```python
# problem 78
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        path = []
        n = len(nums)
        def dfs(i):
            ans.append(path.copy())
            if i == n:
                return

            for j in range(i, n):
                path.append(nums[j])
                dfs(j + 1)
                path.pop()

        dfs(0)
        return ans
```

```python
# problem 131
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        ans = []
        path = []
        n = len(s)
        def dfs(i):
            if i ==n:
                ans.append(path.copy())
                return

            for j in range(i, n):
                t = s[i: j + 1]
                if t == t[::-1]:
                    path.append(t)
                    dfs(j + 1)
                    path.pop()

        dfs(0)
        return ans
```
