class Solution {
public:
    int maxOperations(vector<int>& nums, int K) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int j = 0;
        int k = nums.size() - 1;
        while (j < k)
        {
            if (nums[j] + nums[k] == K)
            {
                count++;
                j++;
                k--;
            }
            else if (nums[j] + nums[k] > K)
                k--;
            else
                j++;
        }
        return count;
    }
};