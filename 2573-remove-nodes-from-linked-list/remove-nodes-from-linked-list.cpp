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
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        while(head!=nullptr){
            ListNode* nextNode = head->next;
            head->next=prev;
            prev=head;
            head=nextNode;

        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);

        int maxEle = head->val;
        ListNode* curr = head;
        while(curr!=nullptr && curr->next!=nullptr){
            if(curr->next->val < maxEle){
                curr->next = curr->next->next;
            }
            else{
                curr =curr->next;
                maxEle=curr->val;
            }
        }
        head = reverse(head);
        return head;
        
    }
};