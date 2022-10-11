class Solution {
public:
    ListNode* add(ListNode *l1, ListNode *l2, int &carry){
        if(l1==NULL || l2==NULL)
            return NULL;
        ListNode *t = new ListNode(0);
        t->next = add(l1->next,l2->next, carry);
        t->val = (l1->val+l2->val+carry)%10;
        carry = (l1->val+l2->val+carry)/10;
        return t;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;
        while(ptr1 || ptr2){
            if(ptr1==NULL){
                ListNode *t = new ListNode(0);
                t->next =l1;
                l1 =t;
                ptr2 = ptr2->next;
            }
             else if(ptr2==NULL){
                ListNode *t = new ListNode(0);
                t->next =l2;
                l2 =t;
                 ptr1 = ptr1->next;
            }
            else{
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }
        int carry =0;
        ListNode *head = add(l1,l2,carry);
        if(carry){
            ListNode *t = new ListNode(carry);
            t->next = head;
            head = t;
        }
        return head;
    }
};
