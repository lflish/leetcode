class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        direct = {};
        
        for (key,value) in enumerate(nums):
            if target - value in direct:
                return key,direct[target - value]
            direct[value] = key  
