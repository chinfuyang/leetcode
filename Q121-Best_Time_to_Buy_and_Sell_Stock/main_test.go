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
		{"example 1", args{[]int{7, 1, 5, 3, 6, 4}}, 5},
		{"example 2", args{[]int{7, 6, 4, 3, 1}}, 0},
	}
}

func TestBestTimeToBuyAndSellStock(t *testing.T) {
	tests := setUpTests()
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := MaxProfit2(tt.args.nums1); got != tt.want {
				t.Errorf("TestBestTimeToBuyAndSellStock() = %v, want %v", got, tt.want)
			}
		})
	}
}
