package main

import "fmt"

func main() {
    // Raw String Literal. 복수라인.
    rawLiteral := `아리랑\n
아리랑\n
아라리요`

    // Interpreted String Literal
    interLiteral := "아리랑아리랑\n아리리요"
    // 아래와 같이 +를 사용하여 두 라인에 걸쳐 사용할 수도 있다.
    // interLiteral := "아리랑아리랑\n" + 
    //                 "아리리요"   

    fmt.Println(rawLiteral)
    fmt.Println()
    fmt.Println(interLiteral)
}
