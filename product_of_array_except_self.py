from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [1] * n
        
        # Calculate left products and store them in the result array
        left_product = 1
        for i in range(n):
            result[i] *= left_product
            left_product *= nums[i]
        
        # Calculate right products and multiply them with the already calculated result
        right_product = 1
        for i in range(n - 1, -1, -1):
            result[i] *= right_product
            right_product *= nums[i]
        
        return result

