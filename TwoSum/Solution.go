package main;

import "fmt"

func twoSum(nums []int, target int) []int {
	a := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		val, ok := a[target - nums[i]]
		if ok {
			res := []int{i, val}
			return res
		} else {
			a[nums[i]] = i
		}
	}
	var res []int
	return res
}

func main() {
	fmt.Println(twoSum([]int{5, 1, 6}, 6))
}
