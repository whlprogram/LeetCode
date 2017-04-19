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
        //*node = *node->next; //直接把后一个结点赋给现在的节结点,但没有彻底删除数据，只是把结点从链表上去掉

        auto next = node->next;
         *node = *next;
         delete next;//彻底删除结点
    }
};
int main()
{
    Solution a;
    cout << "Hello world!" << endl;
    return 0;
}
