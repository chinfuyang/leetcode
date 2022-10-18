package main

import "testing"

type args struct {
	s string
}

type Test struct {
	name string
	args args
	want bool
}

func setUpTests() []Test {
	return []Test{
		{"example 1", args{"()[]"}, true},
		{"example 2", args{"{()}"}, true},
		{"example 3", args{"[(])"}, false},
	}
}
func TestValidParentheses(t *testing.T) {
	tests := setUpTests()
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := isValid(tt.args.s)
			if got != tt.want {
				t.Errorf("TestBestTimeToBuyAndSellStock() = %v, want %v", got, tt.want)
			}
		})
	}
}
