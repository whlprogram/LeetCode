#include <iostream>

using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {//��ת������ ԭ�����ӣ�https://leetcode.com/problems/reverse-linked-list/#/description
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
        head->next = nullptr;//�ɵ�ͷָ�����µ�βָ�� ָ��NULL
        while(q){
            r = q->next;//����������һ��Ҫ�����ָ��
            q->next = p;//p q ���洦�� ���з�ת������
            p = q;
            q = r;
        }
        head = p;//����q�ض�ָ��NULL��p�ͳ����������ͷָ��
        return head;
    }
    //9ms
    //˼·���ֽ������ɻ���ÿ�ζ���ԭ��һ�����֮����Ǹ��������µı�ͷ���棬���Ͽ�����
    //����1,2,3,4,5  ���1,2,3,4,5->1(��)
    //��һ�Σ��ѵ�һ�����1��ߵĽ��2�ŵ��±�ͷ���棬���2,1,3,4,5 ->2(��)
    //�ڶ��Σ��ѵ�һ�����1��ߵĽ��3�ŵ��±�ͷ���棬���3,2,1,4,5 ->3(��)
    //4,3,2,1,5 ->4(��)
    //5,4,3,2,1 ->5(��)
    //�Ͽ��� ����ͷ���
    ListNode* reverseList1(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* res;
        ListNode* first;
        ListNode* temp;
        res = new ListNode(-1);
        res->next = head; //���������ɻ�
        first = head;//ָ��ԭ�����ͷ���
        while(first->next != nullptr){
            temp = first->next;//ָ�򼴽�����ĵ�
            first->next = temp->next;
            temp->next = res->next;
            res->next = temp;
        }
        head = res->next;
        res->next = nullptr;
        return head;
    }
    //�ݹ�
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
