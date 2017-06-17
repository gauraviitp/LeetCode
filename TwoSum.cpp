/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int posA, posB;
        map<int, int> m;
        for(int i = 0; i < nums.size(); ++i){
            if(m.find(target - nums[i]) != m.end()){
                posA = i;
                posB = m[target - nums[i]];
                break;
            }
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = i;
            }
        }
        vector<int> result{posA, posB};
        return result;
    }
};
