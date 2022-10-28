#include <unordered_map>

class Solution
{
public:
    int longestPalindrome(string s) {
      
        std::unordered_map<char, int> umap;

        for (auto const &c : s)
        {
            umap[c]++;
        }

        int maxLength = 0;
        for (auto const &pair: umap)
        {
            if (pair.second % 2 == 0) maxLength += pair.second;
            else maxLength += (pair.second - 1);
        }
        if (s.size() > maxLength) maxLength++;

        return maxLength;  
    }
};