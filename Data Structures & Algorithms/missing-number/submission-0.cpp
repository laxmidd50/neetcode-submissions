class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int target = (n+1)*(n/2);
        if (n%2 != 0)
            target += (n+1)/2;
        
        int total = 0;
        for (int num: nums)
        {
            total += num;
        }

        return target-total;
    }
};
