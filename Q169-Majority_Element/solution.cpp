class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> umap;

        for(auto i : nums)
        {
            if (++umap[i] > nums.size() / 2)
            {
                return i;
            }
        }
        return 0;

    }
};