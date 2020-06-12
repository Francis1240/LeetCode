class Solution {


    public class ListNode {
        int val;
        ListNode next;
        ListNode(){}
        ListNode(int val) {this.val = val;}
        ListNode(int val, ListNode next){
            this.val = val;
            this.next = next;
        }
    };
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        
        if(l1==null || l2 == null){
            if(l1 == null){
                return l2;
            }else{
                return l1;
            }
        }

        if(l1.val>l2.val){
            ListNode rest = mergeTwoLists(l1, l2.next);
            return new ListNode(l2.val, rest);
        }else{
            ListNode rest = mergeTwoLists(l1.next, l2);
            return new ListNode(l1.val, rest);
        }
    }
}