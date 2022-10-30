class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        int num = 0;
        while (n != 0)
        {
            num = n % 2;
            if (num) cnt++;
            n = n / 2;
        }

        return cnt;
    }
};