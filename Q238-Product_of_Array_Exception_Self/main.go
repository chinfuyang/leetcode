package main

import "fmt"

func ProductOfArrayExceptSelf(nums []int) []int {
	len := len(nums)
	ans := make([]int, len)
	ans[0] = 1
	for i := 1; i < len; i++ {
		ans[i] = nums[i-1] * ans[i-1]
	}
	tmp := 1
	for i := len - 1; i > 0; i-- {
		tmp *= nums[i]
		ans[i-1] *= tmp
	}

	return ans
}

func main() {
	fmt.Println(ProductOfArrayExceptSelf([]int{-1, 1, 0, -3, 3}))
}
