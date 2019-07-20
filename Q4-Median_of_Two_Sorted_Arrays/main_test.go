package main

import "testing"

type args struct {
	nums1 []int
	nums2 []int
}

type Test struct {
	name string
	args args
	want float64
}

func setUpTests() []Test {
	return []Test{
		{"example 1", args{[]int{1, 3}, []int{2}}, 2.0},
		{"example 2", args{[]int{1, 2}, []int{3, 4}}, 2.5},
		{"zero test", args{[]int{0, 0}, []int{0, 0}}, 0},
		{"same test", args{[]int{1, 1}, []int{1}}, 1},
		{"left larger test", args{[]int{3, 4}, []int{1, 2}}, 2.5},
		{"left one test", args{[]int{2}, []int{1, 2}}, 2},
		{"cross test", args{[]int{1, 3}, []int{2, 4}}, 2.5},
	}
}

func TestFindMedianSortedArrays(t *testing.T) {
	tests := setUpTests()
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := FindMedianSortedArrays(tt.args.nums1, tt.args.nums2); got != tt.want {
				t.Errorf("FindMedianSortedArrays() = %v, want %v", got, tt.want)
			}
		})
	}
}

func TestFindMedianSortedArraysByMergeAlgorithm(t *testing.T) {
	tests := setUpTests()
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := FindMedianSortedArrays2(tt.args.nums1, tt.args.nums2); got != tt.want {
				t.Errorf("FindMedianSortedArrays() = %v, want %v", got, tt.want)
			}
		})
	}
}
