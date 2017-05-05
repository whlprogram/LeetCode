#include <iostream>

using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {//反转单链表 原题链接：https://leetcode.com/problems/reverse-linked-list/#/description
public:
    //http://blog.csdn.net/feliciafay/article/details/6841115
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* p;
        ListNode* q;
        ListNode* r;
        p = head;
        q = head->next;
        head->next = nullptr;//旧的头指针是新的尾指针 指向NULL
        while(q){
            r = q->next;//用来保存下一步要处理的指针
            q->next = p;//p q 交替处理 进行反转单链表
            p = q;
            q = r;
        }
        head = p;//最后的q必定指向NULL，p就成了新链表的头指针
        return head;
    }
    //9ms
    //思路：现将链表变成环，每次都将原第一个结点之后的那个结点放在新的表头后面，最后断开环。
    //比如1,2,3,4,5  变成1,2,3,4,5->1(环)
    //第一次：把第一个结点1后边的结点2放到新表头后面，变成2,1,3,4,5 ->2(环)
    //第二次：把第一个结点1后边的结点3放到新表头后面，变成3,2,1,4,5 ->3(环)
    //4,3,2,1,5 ->4(环)
    //5,4,3,2,1 ->5(环)
    //断开环 返回头结点
    ListNode* reverseList1(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* res;
        ListNode* first;
        ListNode* temp;
        res = new ListNode(-1);
        res->next = head; //将单链表变成环
        first = head;//指向原链表的头结点
        while(first->next != nullptr){
            temp = first->next;//指向即将处理的点
            first->next = temp->next;
            temp->next = res->next;
            res->next = temp;
        }
        head = res->next;
        res->next = nullptr;
        return head;
    }
    //递归
    //https://discuss.leetcode.com/topic/17916/8ms-c-iterative-and-recursive-solutions-with-explanations/2
    ListNode* reverseList2(ListNode* head) {
        if (!head || !(head -> next)) return head;
        ListNode* node = reverseList2(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
