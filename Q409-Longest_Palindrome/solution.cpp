#include <unordered_map>

class Solution
{
public:
    int longestPalindrome(string s) {
        std::unordered_map<char, bool> umap;

        int groupCount = 0;
        for (auto const &c : s)
        {
            if (umap.find(c) == umap.end())
            {
                umap[c] = true;
            }
            else 
            {
                umap.erase(c);
                groupCount++;
            }
        }

        return groupCount * 2 + umap.empty() ? 0 : 1;
    }
};