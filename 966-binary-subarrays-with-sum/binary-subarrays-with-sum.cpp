class Solution {
public:
    int atmost(vector<int> &nums, int k){
        if(k < 0) return 0;
        int left = 0, sum = 0, cnt = 0;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];

            while(sum > k){
                sum -= nums[left];
                left++;
            }

            cnt += right - left + 1;
        }

        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal - 1);
    }
};