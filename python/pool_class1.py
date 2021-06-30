from multiprocessing import Pool
 
def doubler(number):
    return number * 2
 
if __name__ == '__main__':
    numbers = [5, 10, 20]
    pool = Pool(processes=3)
    print(pool.map(doubler, numbers))
#기본적으로 여기서 발생하는 것은 Pool의 인스턴스를 만들고 세 개의 작업자 프로세스를 생성하도록 지시한다는 것입니다. 그런 다음 map 메소드를 사용하여 함수와 반복 가능한 것을 각 프로세스에 매핑합니다. 마지막으로 결과를 인쇄합니다.이 경우 실제로 목록입니다 : [10, 20, 40].
