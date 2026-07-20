class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos, neg;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                pos.push_back(nums[i]);
            }else{
                neg.push_back(nums[i]);
            }
        }

        if(pos.size() > neg.size()){
            for(int i = 0; i < neg.size(); i++){
                nums[i*2] = pos[i];
                nums[i*2+1] = neg[i];
            }

            int index = neg.size()*2;
            for(int i = neg.size(); i < pos.size(); i++){
                nums[index] = pos[i];
                index++;
            }
        }else{
            for(int i = 0; i < pos.size(); i++){
                nums[i*2] = pos[i];
                nums[i*2+1] = neg[i];
            }

            int index = pos.size()*2;
            for(int i = pos.size(); i < neg.size(); i++){
                nums[index] = neg[i];
                index++;
            }
        }
        return nums;
    }
};