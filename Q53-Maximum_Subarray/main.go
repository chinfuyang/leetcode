package main

import "fmt"

func MaxSubArray(nums []int) int {
	max := -999999999
	len := len(nums)
	tmp := 0
	for i := 0; i < len; i++ {
		tmp += nums[i]
		if tmp <= nums[i] {
			tmp = nums[i]
		}
		if tmp >= max {
			max = tmp
		}
	}
	return max
}

func main() {
	fmt.Println(MaxSubArray([]int{8, -19, 5, -4, 20}))
}
