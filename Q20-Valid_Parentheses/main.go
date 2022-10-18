package main

import (
	"fmt"
)

func isValid(s string) bool {
	bucket := ""
	for i := 0; i < len(s); i++ {
		c := string(s[i])
		if c == "(" || c == "[" || c == "{" {
			bucket += c
			continue
		}
		if len(bucket) == 0 ||
			(c == ")" && string(bucket[len(bucket)-1]) != "(") ||
			(c == "]" && string(bucket[len(bucket)-1]) != "[") ||
			(c == "}" && string(bucket[len(bucket)-1]) != "{") {
			return false
		}
		bucket = bucket[:len(bucket)-1]
	}
	return len(bucket) == 0
}

func isValid2(s string) bool {
	bucket := ""
	for i := 0; i < len(s); i++ {
		c := string(s[i])

		switch c {
		case "(":
			bucket += c
		case "[":
			bucket += c
		case "{":
			bucket += c
		case ")":
			if len(bucket) == 0 || string(bucket[len(bucket)-1]) != "(" {
				return false
			}
			if string(bucket[len(bucket)-1]) == "(" {
				bucket = bucket[:len(bucket)-1]
			}
		case "]":
			if len(bucket) == 0 || string(bucket[len(bucket)-1]) != "[" {
				return false
			}
			if string(bucket[len(bucket)-1]) == "[" {
				bucket = bucket[:len(bucket)-1]
			}
		case "}":
			if len(bucket) == 0 || string(bucket[len(bucket)-1]) != "{" {
				return false
			}
			if string(bucket[len(bucket)-1]) == "{" {
				bucket = bucket[:len(bucket)-1]
			}
		}
	}
	return len(bucket) == 0
}

func main() {
	fmt.Println(isValid("{()}"))
}
