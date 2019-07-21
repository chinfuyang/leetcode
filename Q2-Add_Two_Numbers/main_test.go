package main

import "testing"

type args struct {
	l1 *ListNode
	l2 *ListNode
}

type Test struct {
	name string
	args args
	want *ListNode
}

func setUpTests() []Test {
	return []Test{
		{"example 1", args{newList([]int{2, 4, 3}), newList([]int{5, 6, 4})}, newList([]int{7, 0, 8})},
		{"edge test", args{newList([]int{2, 4, 3}), newList([]int{0, 0, 0})}, newList([]int{2, 4, 3})},
		{"carry test", args{newList([]int{9, 9}), newList([]int{1})}, newList([]int{0, 0, 1})},
		{"carry test", args{newList([]int{1}), newList([]int{9, 9})}, newList([]int{0, 0, 1})},
	}
}

func TestAddTwoNumbers(t *testing.T) {
	tests := setUpTests()
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := addTwoNumbers(tt.args.l1, tt.args.l2)
			for gotNode, wantNode := got, tt.want; gotNode != nil && wantNode != nil; gotNode, wantNode = gotNode.Next, wantNode.Next {
				if gotNode.Val != wantNode.Val {
					t.Errorf("TestAddTwoNumbers() = %v, want %v", got, tt.want)
				}
			}
		})
	}
}
