package main

func main() {
    var m map[int]string

    m = make(map[int]string)
    //추가 혹은 갱신
    m[901] = "Apple"
    m[134] = "Grape"
    m[777] = "Tomato"

    // 키에 대한 값 읽기
    str := m[134]
    println(str)

    noData := m[999] // 값이 없으면 nil 혹은 zero 리턴
    println(noData)

    // 삭제
    delete(m, 777)
}
