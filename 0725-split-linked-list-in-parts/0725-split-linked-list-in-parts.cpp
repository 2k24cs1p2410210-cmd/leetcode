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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        //finding the length
        ListNode* curr = head;
        int length = 0;
        while(curr)
        {
            length+=1;
            curr = curr->next;
        }
        int parts = length/k;
        int rem = length%k;
        int i=1;
        ListNode* node = head;
            for(int i=0;i<k;i++){
             int cw = 0;
             if(rem>0){
                cw = parts+1;
                rem--;
             }
             else{
                cw = parts;
             }
              if(cw==0){
                ans.push_back(nullptr);
                continue;
             }
             ans.push_back(node);
             for(int j=1;j<cw;j++){
                node = node->next;
             }
             ListNode* next = node->next;
             node->next = nullptr;
             node = next;
            }
            return ans;
    }
};