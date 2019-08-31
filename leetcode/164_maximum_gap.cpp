class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // linear time/space
        // invalid case
        if(nums.empty() || nums.size() < 2)
            return 0;
        // valid case
        sort(nums.begin(), nums.end());
        int max_gap = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            max_gap = max(nums[i+1] - nums[i], max_gap);
        }
        return max_gap;
    }
};
