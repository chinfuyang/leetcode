package main // package github.com/YangChinFu/leetcode-go/Q3-Longest_Substring_Without_Repeating_Characters

import (
	"strings"
)

// LengthOfLongestSubstring3 will return the loggest sub string length
// Runtime: 4ms, faster than 92.69%
// Memory Usage: 2.6MB, less than 100.00%
func LengthOfLongestSubstring3(s string) int {
	maxLength := 0
	begin := 0
	for i := 0; i < len(s); i++ {
		if index := strings.Index(s[begin:i], s[i:i+1]); index != -1 {
			begin = begin + index + 1
		}
		if length := i - begin + 1; length > maxLength {
			maxLength = length
		}
	}

	return maxLength
}

// LengthOfLongestSubstring2 will return the loggest sub string length
// Runtime: 8ms, faster than 72.15%
// Memory Usage: 3.1MB, less than 57.97%
func LengthOfLongestSubstring2(s string) int {
	m := make(map[byte]int)
	begin, end := 0, 0
	curLength, maxLength := 0, 0
	for i := 0; i < len(s); i++ {
		m[s[i]]++
		if m[s[i]] > 1 {
			end = i - 1
			for m[s[i]] > 1 && begin <= end {
				m[s[begin]]--
				begin++
			}
		} else {
			end = i
		}
		curLength = end - begin + 1
		if curLength > maxLength {
			maxLength = curLength
		}
	}

	return maxLength
}

// LengthOfLongestSubstring will return the loggest sub string length
// Runtime: 172ms, faster than 19.73%
// Memory Usage: 6.5MB, less than 22.36%
func LengthOfLongestSubstring(s string) int {
	ans := 0
	for i := 0; i < len(s); i++ {
		tmpStr := string(s[i])
		for j := i + 1; j < len(s); j++ {
			if strings.Contains(tmpStr, string(s[j])) {
				break
			}
			tmpStr += string(s[j])
		}
		if len(tmpStr) > ans {
			ans = len(tmpStr)
		}
	}

	return ans
}
