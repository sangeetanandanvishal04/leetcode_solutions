class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mpp = {}

        for i in range(0, len(nums)):
            need = target - nums[i]
            if need in mpp:
                return [mpp[need], i]
            mpp[nums[i]] = i

        return []              