#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<short> s1, s2;
        ListNode *h1 = l1, *h2 = l2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* l3 = new ListNode(), *h3 = l3; // head sentry for result
        stack<short> rev;
        bool up = false;

        while(!(s1.empty()||s2.empty())){
            short sum = s1.top() + s2.top() + up;
            s1.pop();
            s2.pop();
            if(sum<10){
                up = false;
                rev.push(sum);
            }else{
                up = true;
                rev.push(sum%10);
            }
        }

        if(s1.empty() && s2.empty()){
            if(up){
                rev.push(1);
            }
        }
        else if(s1.empty()){
            while(!s2.empty()){
                short sum = s2.top() + up;
                s2.pop();
                if(sum < 10){
                    up = false;
                    rev.push(sum);
                }
                else{
                    up = true;
                    rev.push(sum%10);
                }
            }
            if(up){
                rev.push(1);
            }
        }
        else{
            while(!s1.empty()){
                short sum = s1.top() + up;
                s1.pop();
                if(sum < 10){
                    up = false;
                    rev.push(sum);
                }
                else{
                    up = true;
                    rev.push(sum%10);
                }
            }
            if(up){
                rev.push(1);
            }
        }

        while(!rev.empty()){
            ListNode* temp = new ListNode(rev.top());
            rev.pop();
            l3->next = temp;
            l3 = l3->next;
        }
        
        return h3->next;
    }
};