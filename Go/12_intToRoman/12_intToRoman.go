package q012

import (
	"fmt"
)

var ones = []string{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
var tens = []string{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}
var huns = []string{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}
var thos = []string{"", "M", "MM", "MMM"}

func intToRoman(num int) string {
	if num >= 4000 {
		return ""
	}

	// ones := []string{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
	// tens := []string{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}
	// huns := []string{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}
	// thos := []string{"", "M", "MM", "MMM"}

	return thos[num / 1000 % 10] + huns[num / 100 % 10] + tens[num / 10 % 10] + ones[num % 10]
}

// Test ...
func Test() {
	fmt.Println("12_intToRoman begin")
	fmt.Printf("3: %s\n", intToRoman(3))
	fmt.Printf("4: %s\n", intToRoman(4))
	fmt.Printf("9: %s\n", intToRoman(9))
	fmt.Printf("58: %s\n", intToRoman(58))
	fmt.Printf("1994: %s\n", intToRoman(1994))
	fmt.Println("12_intToRoman end")
}
