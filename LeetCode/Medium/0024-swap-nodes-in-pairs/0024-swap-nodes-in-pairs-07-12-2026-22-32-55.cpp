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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
        return NULL;
        if(!head->next)
        return head;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        ListNode* temp = head;
        int count =0;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        while(p1!=nullptr && p2!=nullptr){
            swap(p1->val,p2->val);
            if(p2->next==nullptr)
            break;
            p1 = p2->next;
            if(p1->next==nullptr)
            break;
            p2 = p1->next;
        }
        
      
        return head;
    }
};