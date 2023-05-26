#include <cmath>



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* sum = head;

        bool carry = false;
        while(l1 || l2 || carry){
            int temp = carry? 0 : 1;
            if(l1){
                temp += l1->val;
                l1 = l1->next;
            }
            if(l2){
                temp += l2->val;
                l2 = l2->next;
            }
            if(temp >= 10){
                carry = true;
                temp %= 10;
            }
            sum->next = new ListNode(temp);
            sum = sum->next;
            carry = false;
        }
        sum = head->next;
        head->next = nullptr;
        delete head;
        return sum;

    }
};

int main(){



    return 0;
}