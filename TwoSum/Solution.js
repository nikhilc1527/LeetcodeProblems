/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let check ={};
    let i =0;
    for (i in nums){
        if(check[target - nums[i]]){
            return [check[target - nums[i]],i];
        }
        check[nums[i]] =i;
    }
};

let res = twoSum([5, 1, 6], 6);
console.log(res);
