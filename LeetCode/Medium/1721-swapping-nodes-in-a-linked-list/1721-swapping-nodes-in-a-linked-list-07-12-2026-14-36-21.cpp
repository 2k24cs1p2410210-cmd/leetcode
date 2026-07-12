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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int length = 0;
        while(temp!=NULL){
            length++;
            temp = temp->next;
        }
        ListNode* p1 = head;
        ListNode* p2 = head;

        int count1 = 1;
        int count2 = 1;

        while(count1!=k){
            p1 = p1->next;
            count1++;
        }

        while(count2!=(length-k+1)){
            p2 = p2->next;
            count2++;
        }

        swap(p1->val,p2->val);
        return head;
        
    }
};