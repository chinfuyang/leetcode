#include <map>

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::map<char, int> rMap;
        for (auto c: ransomNote)
        {
            rMap[c]++;
        }
        for (auto c: magazine)
        {
            if (rMap.find(c) != rMap.end() && rMap[c] != 0)
            {
                rMap[c]--;
            }
        }
        
        for (auto const& pair: rMap)
        {
            if (pair.second != 0)
            {
                return false;
            }
        }
        
        return true;
    }
};