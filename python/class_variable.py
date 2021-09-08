'''
클래스 변수란?
인스턴스 변수가 사람의 이름과 같이 각각의 인스턴스마다 가지고 있는 고유한 데이터라면, 클래스 변수는 한 단체의 단체명과 같이 같은 클래스로 만들어진 모든 인스턴스가 공유하는 데이터입니다.

어떤 회사가 직원들의 연봉을 매년 1회 인상해 주는데 특이하게도 전직원의 연봉을 똑같은 인상률로 인상해준다고 합니다. 올해는 회사 매출이 높아서 전직원의 연봉을 10%씩 올려준다고 하네요. (꿈같은 얘기네요 ㅋ) 이때, 모든 직원들에게 적용되는 공통 인상률이 클래스 변수로 사용할 수 있는 좋은 예입니다.
'''
class Employee(object):
    
    raise_amount = 1.1
    
    def __init__(self, first, last, pay):
        self.first = first
        self.last = last
        self.pay = pay
        self.email = first.lower() + '.' + last.lower() + '@wr.com'
        
    def full_name(self):
        return '{} {}'.format(self.first, self.last)
    
    def apply_raise(self):
        self.pay = int(self.pay * Employee.raise_amount)  #1 클래스 Employee를 사용하여 엑세스

emp_1 = Employee('Sanghee', 'Lee', 50000)
emp_2 = Employee('Minjung', 'Kim', 60000)

print(emp_1.pay)  # 기존 연봉
emp_1.apply_raise()  # 인상률 적용
print(emp_1.pay)  # 오른 연봉



