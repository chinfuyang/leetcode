package main // package github.com/YangChinFu/leetcode-go/Q3-Longest_Substring_Without_Repeating_Characters

import (
	"sort"
)

// FindMedianSortedArrays2 use merge algorithm resolve this problem
// RuntimeL 16ms, faster than 72.97%
// Memory Usage: 5.9MB, less than 22.42%
func FindMedianSortedArrays2(nums1 []int, nums2 []int) float64 {
	intMax := int(^uint(0) >> 1)
	leftLen, rightLen := len(nums1), len(nums2)
	ansSlice := make([]int, leftLen+rightLen)
	leftIdx, rightIdx := 0, 0

	nums1 = append(nums1, intMax)
	nums2 = append(nums2, intMax)

	for i := 0; i < leftLen+rightLen; i++ {
		if nums1[leftIdx] <= nums2[rightIdx] {
			ansSlice[i] = nums1[leftIdx]
			leftIdx++
		} else if rightIdx < rightLen {
			ansSlice[i] = nums2[rightIdx]
			rightIdx++
		}
	}

	if len(ansSlice)%2 != 0 {
		return float64(ansSlice[len(ansSlice)/2])
	}

	return float64(ansSlice[len(ansSlice)/2-1]+ansSlice[len(ansSlice)/2]) / 2
}

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
}
