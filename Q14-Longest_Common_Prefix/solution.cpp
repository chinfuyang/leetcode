class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        
        int min = 201;
        for (auto str : strs)
        {
            if (min > str.size())
            {
                min = str.size();
            }
        }

        std::string lcp;
        for(int i = 0; i < min; i++)
        {
            char c = strs[0][i];
            bool same = true;
            for (int j = 1; j < strs.size(); j++)
            {
                if (c != strs[j][i])
                {
                    same = false;
                    break;
                }
            }
            if (same)
                lcp.append(1, c);
            else
                break;
        }

        return lcp;
    }
};