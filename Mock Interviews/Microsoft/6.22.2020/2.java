import java.util.*;


class MyQueue {
    
    private Deque<Integer> stack = new ArrayDeque<>();
    private Deque<Integer> tempStack = new ArrayDeque<>();

    /** Initialize your data structure here. */
    public MyQueue() {
        super();    
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        stack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        int result = -1;
        while(!stack.isEmpty()){
            result = stack.pop();
            tempStack.push(result);
        }
        tempStack.pop();
        while(!tempStack.isEmpty()){
            stack.push(tempStack.pop());
        }
        return result;
    }
    
    /** Get the front element. */
    public int peek() {
        int result = -1;
        while(!stack.isEmpty()){
            result = stack.pop();
            tempStack.push(result);
        }
        while(!tempStack.isEmpty()){
            stack.push(tempStack.pop());
        }
        return result;
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return stack.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */