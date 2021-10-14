package main

type dict struct {
    data map[int]string
}

//생성자 함수 정의
func newDict() *dict {
    d := dict{}
    d.data = map[int]string{}
    return &d //포인터 전달
}

func main() {
    dic := newDict() // 생성자 호출
    dic.data[1] = "A"
    println(dic.data[1])
}
