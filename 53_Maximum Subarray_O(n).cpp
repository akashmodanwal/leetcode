class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=0;
        int max = -9999999;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
                ans=1;
            if(max<nums[i])
                max=nums[i];
        }
        if(ans==1){
            int maxhere = 0;
            int max= 0;
            for(int i=0;i<nums.size();i++){
                if(maxhere+nums[i]<0)
                    maxhere=0;
                else
                    maxhere += nums[i];

                if(maxhere>max)
                    max = maxhere;
            }
            return max;
        }
        else
            return max;
        
    }
};
