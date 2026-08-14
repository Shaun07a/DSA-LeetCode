class Solution {
public:
    int atmost(vector<int> &nums, int k){
        if(k < 0) return 0;
        int left = 0;
        int sum = 0;
        int cnt = 0;
        for(int right = 0; right < nums.size(); right++){
            sum += (nums[right]%2);
            while(sum > k){
                sum -= (nums[left]%2);
                left++;
            }

            cnt += right - left + 1;

        }

        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums, k - 1);
    }
};