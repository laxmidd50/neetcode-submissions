class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr;
        arr.push_back(0);
        for (int i = 1; i <= n; i++)
        {
            int count = arr[i >> 1] + (i & 0x01);
            arr.push_back(count);
        }
        return arr;
    }
};
