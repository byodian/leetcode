"""
Given an array of integers `nums` and an integer `target`, return indices of
the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution.

```Python
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
````
"""

class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        hash_table = {}
        for i in range(len(nums)):
            difference = target - nums[i]
            j = hash_table.get(difference)

            if difference in hash_table and i != j:
                return [j, i]
            else:
                hash_table[nums[i]] = i
            
        return []
