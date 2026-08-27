/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* s= headA;
        ListNode* t= headB;
        int lena=0,lenb=0;
        while(s!=nullptr){
            lena++;
            s=s->next;
        }
        while(t!=nullptr){
            lenb++;
            t=t->next;
        }
        s=headA;
        t=headB;
        if(lena>lenb){
            for(int i=0;i<lena-lenb; i++){
                s=s->next;
            }
        }
        else{
            for(int i=0;i<lenb-lena; i++){
                t=t->next;
            }
        }
        while(s!=nullptr || t!=nullptr){
            if(s== t){
             return s;
            }
        s=s->next;
        t=t->next;

        }
        return nullptr;
    }
};