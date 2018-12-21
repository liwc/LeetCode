package q014

import (
	"fmt"
	"strings"
)

func longestCommonPrefix(strs []string) string {
	l := len(strs)
	if l == 0 {
		return ""
	} else if l == 1 {
		return strs[0]
	}

	// horizontal
	lcp := strs[0]
	for i := 1; i < l; i++ {
		for strings.Index(strs[i], lcp) != 0 {
			lcp = lcp[0: len(lcp) - 1]
			if lcp == "" {
				return ""
			}
		}
	}

	// vertical
	for i := 0; i < len(strs[0]); i++ {
		ch := strs[0][i]
		for j := 1; j < l; j++ {
			if len(strs[j]) < i + 1 || strs[j][i] != ch {
				return strs[0][0: i]
			}
		}
	}

	return lcp
}

// Test ...
func Test() {
	fmt.Println("14_longestCommonPrefix begin")
	strs := []string{
		"flower",
		"flow",
		"flight",
	}
	fmt.Printf("%v\n", longestCommonPrefix(strs))
	fmt.Println("14_longestCommonPrefix end")
}
