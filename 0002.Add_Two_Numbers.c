#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    //Set up pointers.
    struct ListNode* it1 = l1;
    struct ListNode* it2 = l2;
    struct ListNode* h = malloc(sizeof *h);
    struct ListNode* r = h;
    
    //Set up short (better: bool) to indicate carry, and sum.
    short c = 0;
    int sum = 0;
    

    while(it1 || it2){// end when both null
        sum = c;
        if (it1){
            sum += it1->val;
            it1 = it1->next;
        }
        if (it2){
            sum += it2->val;
            it2=it2->next;
        }
        
        c = sum>9?1:0;

        sum %= 10;

        r->val = sum;
        if(!it1&&!it2){
            if(c){
                r->next = malloc(sizeof *r);
                r = r->next;
                r->val = c;
                r->next = NULL;
                break;
            }
            r->next = NULL;
            break;
        }
        r->next = malloc(sizeof *r);
        r=r->next;
        r->next = NULL;
        r->val = 0;
    }
    return h;
}
