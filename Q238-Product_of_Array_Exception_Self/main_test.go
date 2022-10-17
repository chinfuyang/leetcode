package main

import "testing"

type args struct {
	nums1 []int
}

type Test struct {
	name string
	args args
	want []int
}

func setUpTests() []Test {
	return []Test{
		{"example 1", args{[]int{1, 2, 3, 4}}, []int{24, 12, 8, 6}},
		{"example 2", args{[]int{-1, 1, 0, -3, 3}}, []int{0, 0, 9, 0, 0}},
	}
}
func TestProductOfArrayExceptSelf(t *testing.T) {
	tests := setUpTests()
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := ProductOfArrayExceptSelf(tt.args.nums1)
			for i, num := range got {
				if num != tt.want[i] {
					t.Errorf("TestBestTimeToBuyAndSellStock() = %v, want %v", got, tt.want)
				}
			}
		})
	}
}
