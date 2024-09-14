class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int length = 0;
        int max_val =0;

        for(int i = 0; i<nums.size();i++)
        {
            max_val=max(max_val, nums[i]);
        }

        int count = 0;
        for(int i = 0; i<nums.size();i++)
        {
            if(nums[i]==max_val)
            {
                count++;
                length = max(length,count);
            }
            else
            {
                count = 0;
            }
        }
         return  length;

    }
};