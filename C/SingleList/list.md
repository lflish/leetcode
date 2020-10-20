
### 单链表
single_list.c
single_list_ex.c

### 双链表
DoubleList.c


### 双指针场景

-   两个指针从不同位置出发：一个从始端开始，另一个从末端开始
-   两个指针以不同速度移动：一个指针快一些，另一个指针慢一些

对于单链表，因为我们只能在一个方向上遍历链表，所以第一种情景可能无法工作。然而，第二种情景，也被称为慢指针和快指针技巧，是非常有用的。

给定一个链表，判断是否有环
bool hasCycle(struct ListNode *head);

给定一个链表，如果是环形链表，返回入环节点
struct ListNode *detectCycle(struct ListNode *head);

删除链表倒数第N个节点 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)

查找两个链表是否有相交链表                               
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode)


### 链表经典问题

反转链表
struct ListNode* reverseList(struct ListNode* head);

移除链表元素
struct ListNode* removeElements(struct ListNode* head);

奇数偶数链表(给定一个单链表，把所有的奇数节点和偶数节点分别排在一起)
struct ListNode* oddEvenList(struct ListNode* head);

回文链表(判断链表是否是回文链表)
bool isPalindrome(struct ListNode *head);

### 其他链表问题

合并两个升序链表
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

两链表表示数字相加
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

扁平化多及双向链表(python)(leetcode此题不支持C语言)
flatten.py

复制带随即指针的链表
struct Node* copyRandomList(struct Node* head);

旋转链表
struct ListNode* rotateRight(struct ListNode* head, int k);