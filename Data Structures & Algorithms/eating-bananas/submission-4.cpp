class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1;
        int j = 0;
        int k = 0;
        for (const int & x: piles)
        {
            if (x > j)
                j = x;
        }

        while (i <= j)
        {
            int mid = i + ((j - i) / 2);
            if (testK(piles, h, mid))
            {
                j = mid - 1;
                k = mid;
            }
            else
            {
                i = mid + 1;
            }
        }
        return k;
    }

    bool testK(const vector<int> & piles, const int h, const int k)
    {
        int time = 0;
        for (const int & x: piles)
        {
            time += x / k;
            if (x % k > 0)
                time++;
            if (time > h)
                return false;
        }
        if (time > h)
            return false;
        else
            return true;
    }
};
