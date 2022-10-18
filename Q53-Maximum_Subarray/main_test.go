package main

import "testing"

type args struct {
	nums1 []int
}

type Test struct {
	name string
	args args
	want int
}

func setUpTests() []Test {
	return []Test{
		{"example 1", args{[]int{-2, 1, -3, 4}}, 4},
		{"example 2", args{[]int{1}}, 1},
		{"example 3", args{[]int{5, 4, -1, 7, 8}}, 23},
		{"example 4", args{[]int{-2, -1, -3}}, -1},
		{"example 5", args{[]int{-2, -1, -3, 0}}, 0},
		{"example 6", args{[]int{8, -19, 5, -4, 20}}, 21},
		{"example 7", args{[]int{-1, 0, -1, 2, -3, 1, 2, 3, -2}}, 6},
	}
}
func TestMaxSubArray(t *testing.T) {
	tests := setUpTests()
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := MaxSubArray(tt.args.nums1)
			if got != tt.want {
				t.Errorf("TestMaxSubArray() = %v, want %v", got, tt.want)
			}
		})
	}
}
