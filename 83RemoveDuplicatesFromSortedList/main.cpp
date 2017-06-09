//原题链接 https://leetcode.com/problems/remove-duplicates-from-sorted-list/#/description
//题解 http://blog.csdn.net/whl_program/article/details/72973227
#include <iostream>

using namespace std;

 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    //递归
    ListNode* deleteDuplicates(ListNode* head) {//9ms
        ListNode* temp = head;
        return Delete(head, temp);
    }
    ListNode* Delete(ListNode* head, ListNode* temp) {
        if(head == nullptr || head->next == nullptr)
            return temp;
        if(head->val == head->next->val)
            head->next = head->next->next;
        else//只有前后两个节点值不一样才可以head = head->next; 注意连续三个相同数的情况
            head = head->next;
        return Delete(head, temp);
    }

    //循环
    ListNode* deleteDuplicates1(ListNode* head) {//12ms
        if(head == nullptr)
            return head;
        ListNode* temp = head;
        while(temp != nullptr){
            if(temp->next == nullptr)
                break;
            if(temp->val == temp->next->val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return head;
    }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
