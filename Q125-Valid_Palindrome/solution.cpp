#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::string bucket;
        for (auto c:s) {
            if (c >= 'A' && c <= 'Z') {
                c = c- 'A' + 'a';
            }
            if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                bucket += c;
            }
        }
        if (bucket.size() == 0 || bucket.size() == 1) {
            return true;
        }

        for (int i = 0; i < bucket.size() / 2 ; i++) {
            if (bucket[i] != bucket[bucket.size()-1-i]) {
                return false;
            }
        }

        return true;
    }
    
    bool isValid2(std::string s) {
        int l = 0;
        int r = s.size()-1;
        while (l < r) {
            if (!isalnum(s[l])) l++;
            else if (!isalnum(s[r])) r--;
            else if (tolower(s[l]) != tolower(s[r])) return false;
            else {l++;r--;}
        }

        return true;
    }
};