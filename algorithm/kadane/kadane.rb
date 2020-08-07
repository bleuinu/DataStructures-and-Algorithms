=begin
Given an array, the algorithm to find the maximum subarray sum is called Kadane’s Algorithm.
The array can be of any dimension. For simplicity, let’s start with a 1D array.
=end

def max (a,b)
  a>b ? a : b
end
def kadane(nums)
  _max = nums[0]
  curr = _max
  1.upto(nums.length-1) do |i|
    curr = max(nums[i], nums[i] + curr)
    _max = _max > curr ? _max : curr
  end
  _max
end

def kadane2(nums)
  max = nums[0]
  1.upto(nums.length-1) do |i|
    nums[i] = (nums[i] > nums[i]+nums[i-1]) ? nums[i] : nums[i]+nums[i-1]
    max = max > nums[i] ? max : nums[i]
  end
  max
end
puts kadane([-2,1,-3,4,-1,2,1,-5,4]) # 6
puts kadane([1,-2,3,4]) # 7

puts kadane2([-2,1,-3,4,-1,2,1,-5,4]) # 6
puts kadane2([1,-2,3,4]) # 7
