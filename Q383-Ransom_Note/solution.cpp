#include <unordered_map>
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> map;
        for (auto c: magazine)
        {
            map[c]++;
        }
        
        for (auto c: ransomNote)
        {
            if (--map[c] < 0)
            {
                return false;
		    };
        }
        return true;
    }
};