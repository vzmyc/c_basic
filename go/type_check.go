package main

import "fmt"

import "reflect"



func main() {



  var x, y = 1, "2"

  fmt.Println(x, y)

  fmt.Println(reflect.TypeOf(x))

  fmt.Println(reflect.TypeOf(y))

  fmt.Println()



  m := 1.2

  fmt.Println(m)

  fmt.Println(reflect.TypeOf(m))

}
