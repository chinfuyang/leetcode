package main // package github.com/YangChinFu/leetcode-go/Q771-Jewels_and_Stones

// numJewelsInStones
// Runtime: 0ms, faster than 100.00%
// Memory Usage: 2.1MB, less than 32.79%
func numJewelsInStones(J string, S string) int {
	jewels := make(map[rune]bool)
	for _, j := range J {
		jewels[j] = true
	}
	cnt := 0
	for _, s := range S {
		if jewels[s] {
			cnt++
		}
	}
	return cnt
}

func main() {
	numJewelsInStones("aA", "aAAbbbb")
	return
}
