class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr;
        for (int i = 0; i <= n; i++)
        {
            int j = i;
            int count = 0;
            while (j != 0)
            {
                count += j & 0x01;
                j = j >> 1;
            }
            arr.push_back(count);
        }
        return arr;
    }
};
