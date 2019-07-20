package main

import "testing"

type args struct {
	J string
	S string
}

type Test struct {
	name string
	args args
	want int
}

func setUpTests() []Test {
	return []Test{
		{"example 1", args{"aA", "aAAbbbb"}, 3},
		{"example 2", args{"z", "ZZ"}, 0},
		{"empty test", args{"", "aAAbbbbb"}, 0},
		{"larger j test", args{"abcsd", "aw"}, 1},
	}
}

func TestNumJewelsInStones(t *testing.T) {
	tests := setUpTests()
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := numJewelsInStones(tt.args.J, tt.args.S); got != tt.want {
				t.Errorf("FindMedianSortedArrays() = %v, want %v", got, tt.want)
			}
		})
	}
}
