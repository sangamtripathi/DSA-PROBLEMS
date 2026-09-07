/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return head;
        }

        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        ListNode* prev = dummy;


        while(temp){
            if(temp->val==val){
                prev->next=temp->next;
                temp->next=nullptr;
                temp=prev->next;
            }else{
                prev=prev->next;
                temp=temp->next;
                prev->next=temp;
            }
        }
        return dummy->next;
    }
};