# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
  a = {}
  nums.each_with_index { |val, index|
    if a.has_key?(target - val)
      return [index, a[target - val]]
    else
      a[val] = index
    end
  }                  
end

a = two_sum([5, 1, 6], 6)
puts a
