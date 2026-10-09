class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t out = 0;
        for (int i = 0; i < 32; i++)
        {
            if (i > 0)
            {
                out = out << 1;
                n = n >> 1;
            }

            out = out | (n & 0x01);
        }
        return out;
    }
};
