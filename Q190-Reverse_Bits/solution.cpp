class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        int digit = 0;
      
        for (int i = 0; i < 32; i++)
        { 
            digit = n & 1;
            ret <<= 1;
            ret += digit;
            n >>= 1;
        }
        
        return ret;
    }
};