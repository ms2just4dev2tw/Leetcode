
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        ListNode *leftMaxNode = head;
        ListNode *leftNode = head, *rightNode = head->next;
        while (rightNode != nullptr)
        {
            if (leftNode->val > rightNode->val) {
                leftNode = leftNode->next;
                rightNode = rightNode->next;
            } else if (leftMaxNode->val < rightNode->val) {
                leftMaxNode = rightNode;
                leftNode = rightNode;
                rightNode = rightNode->next;
            } else {
                ListNode *tmp1 = leftMaxNode;
                ListNode *tmp2 = leftMaxNode->next;
                
                while (tmp2 != rightNode) {
                    if (tmp2->val > tmp1->val) {
                        tmp1 = tmp1->next;
                        tmp2 = tmp2->next;
                    } else {
                        tmp2 = tmp2->next;
                        tmp1->next = tmp2;
                    }
                }
            }
        }
        
    }
};

int main(void) {
    Solution solution;
}