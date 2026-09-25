class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = 0;
        for (int i = 0; i < 32; i++)
        {
            x = x << 1;
            x = x | (n & 0x00000001);
            n = n >> 1;
        }
        return x;
    }
};
