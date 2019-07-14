package main // package github.com/YangChinFu/leetcode-go/2

import (
	"strings"
)

// LengthOfLongestSubstring will return the loggest sub string length
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

func main() {
	
}
