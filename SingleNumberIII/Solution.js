/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumber = function(nums) {
    let a = new Set();
    for (let b = 0; b < nums.length; b++) {
        let i = nums[b];
        if (a.has(i)) {
            a.delete(i);
        }
        else {
            a.add(i);
        }
    }
    return [...a];
};

console.log(singleNumber([3, 1, 3, 2]));
