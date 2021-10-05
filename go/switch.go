package main
import "fmt"
import "time"
func main(){
  //가장 기본적인 switch문입니다.
  i := 2
  fmt.Print("Write ", i, "as")
  switch i {
    case 1:
      fmt.Println("one")
    case 2:
      fmt.Println("one")
    case 3:
      fmt.Println("one")
  }

  //쉼표를 사용하여 동일한 case 문에서 여러 표현식을 분리 할 수 있습니다.
  //이 예제에서 선택적인 default 경우도 사용합니다.
  switch time.Now().Weekday(){
  case time.Saturday, time.Sunday:
    fmt.Println("It's the weekend")
  default:
    fmt.Println("It's a weekday")
  }

  //식이없는 스위치는 if / else 로직을 표현하는 대체 방법입니다.
  //여기에서는 사례 표현이 비 상수일 수있는 방법을 보여줍니다.
  t := time.Now()
  switch {
    case t.Hour() < 12:
      fmt.Println("It's before noon")
    default:
      fmt.Println("It's after noon")
  }

  //유형 스위치는 값 대신 유형을 비교합니다. 이를 사용하여 인터페이스 값의 유형을 발견 할 수 있습니다.
  //이 예제에서 변수 t는 해당 절에 해당하는 유형을 갖습니다.
  whatAmI := func(i interface{}){
    switch t := i.(type){
      case bool:
        fmt.Println("I'm a bool")
      case int:
        fmt.Println("I'm an int")
      default:
        fmt.Printf("Don't know type %T\n", t)
    }
  }
  whatAmI(true)
  whatAmI(1)
  whatAmI("hey")
}
