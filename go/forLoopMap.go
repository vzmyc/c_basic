package main

import "fmt"

func main() {
    myMap := map[string]string{
        "A": "Apple",
        "B": "Banana",
        "C": "Charlie",
    }

    // for range 문을 사용하여 모든 맵 요소 출력
    // Map은 unordered 이므로 순서는 무작위
    for key, val := range myMap {
        fmt.Println(key, val)
    }
}
