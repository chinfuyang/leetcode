package main

import "testing"

type Test struct {
	name string
	args string
	want int
}

func setUpTests() []Test {
	return []Test{
		{"normal test", "abcabcbb", 3},
		{"repeat test", "bbbbbbbb", 1},
		{"compolex test", "pwwkew", 3},
		{"edge test", "", 0},
		{"other test", "abcabcdbb", 4},
		{"other test", "abcdefedcba", 6},
		{"right length test", "aaaaabcdeaddddhijklmqpr", 10},
		{"center length test", "aaaaabcdefghijkwwwwwwwww", 12},
		{"left length test", "abcdefghirrrrrrrrrrrr", 10},
		{"leetcode test", "dvdf", 3},
	}
}

func TestLengthOfLongestSubstringBrute(t *testing.T) {
	tests := setUpTests()
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := LengthOfLongestSubstring(tt.args); got != tt.want {
				t.Errorf("lengthOfLongestSubstring() = %v, want %v", got, tt.want)
			}
		})
	}
}

func BenchmarkLengthOfLongestSubstringBrute(b *testing.B) {
	tests := setUpTests()
	for _, tt := range tests {
		b.Run(tt.name, func(b *testing.B) {
			if got := LengthOfLongestSubstring(tt.args); got != tt.want {
				b.Errorf("lengthOfLongestSubstring() = %v, want %v", got, tt.want)
			}
		})
	}
}

func TestLengthOfLongestSubstringSlideWindow(t *testing.T) {
	tests := setUpTests()
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := LengthOfLongestSubstring2(tt.args); got != tt.want {
				t.Errorf("lengthOfLongestSubstring() = %v, want %v", got, tt.want)
			}
		})
	}
}

func TestLengthOfLongestSubstringGolangSubstring(t *testing.T) {
	tests := setUpTests()
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := LengthOfLongestSubstring3(tt.args); got != tt.want {
				t.Errorf("lengthOfLongestSubstring() = %v, want %v", got, tt.want)
			}
		})
	}
}
