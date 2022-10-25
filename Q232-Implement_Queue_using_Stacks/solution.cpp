#include <stack>

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        _stack.push(x);
    }
    
    int pop() {
		while( ! _stack.empty()) {
			_stack2.push(_stack.top());
			_stack.pop();
		}
		int top = _stack2.top();
		_stack2.pop();
		while(! _stack2.empty()) {
			_stack.push(_stack2.top());
			_stack2.pop();
		}

		return top;
    }
    
    int peek() {
		while( ! _stack.empty()) {
			_stack2.push(_stack.top());
			_stack.pop();
		}
		int top = _stack2.top();
		while(! _stack2.empty()) {
			_stack.push(_stack2.top());
			_stack2.pop();
		}

		return top;
    }
    
    bool empty() {
        return _stack.empty();
    }

private:
	std::stack<int> _stack;
    std::stack<int> _stack2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */