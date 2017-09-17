package main
 
import (
    "fmt"
)
 
func main() {
    tehNumbers := []int{1, 5, 4, 2, 6, 5, 3, 6, 7, 4}
    toCompare := 0 // or min_int or whatever, a bool to say first element idk depends if they can be -ve
    for i, n := range tehNumbers {
        if n > tehNumbers[toCompare] {
            for j := toCompare; j < i; j++ {
                tehNumbers[j] = i
            }
            toCompare = i
        }
    }
    for i := toCompare; i < len(tehNumbers); i++ {
        tehNumbers[i] = -1
    }
    fmt.Printf("%v", tehNumbers)
}
