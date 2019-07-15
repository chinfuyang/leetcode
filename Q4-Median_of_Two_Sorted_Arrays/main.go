package main //  package github.com/YangChinFu/leetcode-go/Q4-Median_of_Two_Sorted_Arrays

import "sort"

// FindMedianSortedArrays use golang library to resolve this problem
// RuntimeL 12ms, faster than 89.76%
// Memory Usage: 5.9MB, less than 38.13%
func FindMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	nums1 = append(nums1, nums2...)
	sort.Ints(nums1)
	if len(nums1)%2 != 0 {
		return float64(nums1[len(nums1)/2])
	}

	return float64(nums1[len(nums1)/2-1]+nums1[len(nums1)/2]) / 2
}

func main() {
	FindMedianSortedArrays([]int{1, 3}, []int{2, 4})
}
