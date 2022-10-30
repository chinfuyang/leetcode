class Solution {
public:
    bool backspaceCompare(string s, string t) {
        std::string newS, newT;
        for(auto c: s)
        {
            if (c == '#')
            {
                if (! newS.empty())
                    newS.pop_back();
                continue;
            }
            else
                newS.append(1, c);
        }
        for(auto c: t)
        {
            if (c == '#')
            {
                if (! newT.empty())
                    newT.pop_back();
                continue;
            }
            else
                newT.append(1, c);
        }

        return newS == newT;
    }
};