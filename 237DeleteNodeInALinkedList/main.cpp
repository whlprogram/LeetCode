#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        //*node = *node->next; //ֱ�ӰѺ�һ����㸳�����ڵĽڽ��,��û�г���ɾ�����ݣ�ֻ�ǰѽ���������ȥ��

        auto next = node->next;
         *node = *next;
         delete next;//����ɾ�����
    }
};
int main()
{
    Solution a;
    cout << "Hello world!" << endl;
    return 0;
}
