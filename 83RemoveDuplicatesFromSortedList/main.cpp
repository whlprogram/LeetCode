//原题链接 https://leetcode.com/problems/remove-duplicates-from-sorted-list/#/description
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        return Delete(head, temp);
    }
    ListNode* Delete(ListNode* head, ListNode* temp) {
        if(head == nullptr || head->next == nullptr)
            return temp;
        if(head->val == head->next->val)
            head->next = head->next->next;
        else
            head = head->next;
        return Delete(head, temp);
    }

    //循环
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        return Delete(head, temp);
    }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
