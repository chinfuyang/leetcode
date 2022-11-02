class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        std::queue<int> _q;
        std::stack<int> _s;
        
        while(x > 0)
        {
            int digit = x % 10;
            _q.push(digit);
            _s.push(digit);
            x /= 10;
        }
        
        while (! _s.empty())
        {
            int front = _q.front();
            int top = _s.top();
            _q.pop();
            _s.pop();
            if (front != top) return false;
        }
        
        
        return true;
    }
};