/**
 * @param {number[]} nums
 * @return {number}
 */
let findMin = function(nums) {
    if (nums.length < 2) return nums[0];
    let lo = 0, hi = nums.length - 1;
    while (lo < hi) {
        if (nums[lo] < nums[hi]) {
            hi = lo;
            lo = 0;
        }
        else {
            let mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[lo]) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
    }
    return Math.min(nums[lo], nums[lo + 1]);
};

console.log(findMin([2, 2, 2, 0, 1]));
