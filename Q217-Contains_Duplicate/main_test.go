package main

import "testing"

type args struct {
	nums1 []int
}

type Test struct {
	name string
	args args
	want bool
}

func setUpTests() []Test {
	return []Test{
		{"example 1", args{[]int{1, 2, 3, 1}}, true},
		{"example 2", args{[]int{1, 2, 3, 4}}, false},
	}
}

func TestContainsDuplicate(t *testing.T) {
	tests := setUpTests()
	for _, test := range tests {
		t.Run(test.name, func(t *testing.T) {
			if got := ContainsDuplicate(test.args.nums1); got != test.want {
				t.Errorf("TestContainsDuplicate() = %v, want %v", got, test.want)
			}
		})
	}
}
