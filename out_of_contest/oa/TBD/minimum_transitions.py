
def work(nums):
    ones = nums.count(1)
    return ones - max(sum(nums[:ones]), sum(nums[ones:]))

print(work([0, 0, 0, 0, 1]))