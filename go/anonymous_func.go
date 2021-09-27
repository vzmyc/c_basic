package main

func main() {
    sum := func(n ...int) int { //익명함수 정의
        s := 0
        for _, i := range n {
            s += i
        }
        return s
    }

    result := sum(1, 2, 3, 4, 5) //익명함수 호출
    println(result)
}
