package q010

import (
	"fmt"
)

func isRegularMatch(s, p string) bool {
	if p == "" {
		return s == ""
	}

	firstMatch := (s != "" && s[0] == p[0] || p[0] == '.')
	if len(p) >= 2 && p[1] == '*' {
		return isRegularMatch(s, p[2:]) || firstMatch && isRegularMatch(s[1:], p)
	} 
	return firstMatch && isRegularMatch(s[1:], p[1:])
}

// Test ...
func Test() {
	fmt.Println("10_isRegularMatch begin")
	fmt.Printf("s = \"aa\", p = \"a\": %v\n", isRegularMatch("aa", "a"))
	fmt.Printf("s = \"aa\", p = \"a*\": %v\n", isRegularMatch("aa", "a*"))
	fmt.Printf("s = \"aa\", p = \".*\": %v\n", isRegularMatch("aa", ".*"))
	fmt.Printf("s = \"aab\", p = \"c*a*b\": %v\n", isRegularMatch("aab", "c*a*b"))
	fmt.Printf("s = \"mississippi\", p = \"mis*is*p*.\": %v\n", isRegularMatch("mississippi", "mis*is*p*."))
	fmt.Println("10_isRegularMatch end")
}
