class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> ans(nums.size(),1);
        vector<int> left_p(nums.size(),1);
        vector<int> right_p(nums.size(),1);
        
        left_p[0] = 1;
        for(int i=1;i<nums.size();i++){
            left_p[i] = left_p[i-1]*nums[i-1];
        }
        
        right_p[nums.size()-1] = 1;
        for(int i=nums.size()-2;i>=0;i--){
            right_p[i] = right_p[i+1] * nums[i+1];
        }
        
        for(int i=0;i<nums.size();i++){
            ans[i] = left_p[i] * right_p[i];
        }
        
        return ans;
    }
};
