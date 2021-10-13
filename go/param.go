package main

import "fmt"

// 파라미터 없는 함수 작성
func sayHi() {
	fmt.Println("hi!")
}

// 파라미터를 지정한 함수 작성
func sayName(name string) {
	fmt.Println(name)
}

// 메인
func main() {
	sayHi()
	sayName("Jone")
}
