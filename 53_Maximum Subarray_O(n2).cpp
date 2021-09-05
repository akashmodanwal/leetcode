class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> suffix;
        suffix.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            suffix.push_back(suffix[i-1] + nums[i]);
        }
        int max = -9999999;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int sum;
                if(i==0)
                    sum = suffix[j];
                else
                    sum = suffix[j] -suffix[i-1];
                if(sum>max)
                    max = sum;
            }
        }
        return max;
    }
};
