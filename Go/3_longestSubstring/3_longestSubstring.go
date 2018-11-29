package q003

import (
	"fmt"
)

func longestSubstring(str string) int {
	maxlen := 0
	submap := make(map[rune]int, 0)
	i := 0
	for j, ch := range str {
		if pos, ok := submap[ch]; ok {
			if pos > i {
				i = pos
			}
		}

		if j-i+1 > maxlen {
			maxlen = j - i + 1
		}
		submap[ch] = j + 1
	}

	return maxlen
}

func longestSubstring2(str string) int {
	maxlen := 0
	index := make([]int, 128)
	i := 0
	for j, ch := range str {
		if index[ch] > i {
			i = index[ch]
		}

		if j-i+1 > maxlen {
			maxlen = j - i + 1
		}
		index[ch] = j + 1
	}

	return maxlen
}

// Test ...
func Test() {
	fmt.Println("3_longestSubstring begin")
	str := "abcba"

	fmt.Printf("use map: %d\n", longestSubstring(str))
	fmt.Printf("use array: %d\n", longestSubstring2(str))
	fmt.Println("3_longestSubstring end")
}
