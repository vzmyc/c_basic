"""
Pattern		Descript						Example
^		이 패턴으로 시작해야 함				^abc : abc로 시작해야 함 (abcd, abc12 등)
$		이 패턴으로 종료되어야 함				xyz$ : xyz로 종료되어야 함 (123xyz, strxyz 등)
[문자들]		문자들 중에 하나이어야 함. 				[Pp]ython : "Python" 혹은 "python"
[^문자들]		[문자들]의 반대로 피해야할 문자들의 집합을 정의함.	[^aeiou] : 소문자 모음이 아닌 문자들
|		두 패턴 중 하나이어야 함 (OR 기능)			a | b : a 또는 b 이어야 함
?		앞 패턴이 없거나 하나이어야 함 			\d? : 숫자가 하나 있거나 없어야 함
+		앞 패턴이 하나 이상이어야 함			\d+ : 숫자가 하나 이상이어야 함
*		앞 패턴이 0개 이상이어야 함				\d* : 숫자가 없거나 하나 이상이어야 함
패턴{n}		앞 패턴이 n번 반복해서 나타나는 경우			\d{3} : 숫자가 3개 있어야 함
패턴{n, m}	앞 패턴이 최소 n번, 최대 m 번 반복해서 나타나는 경우 (n 또는 m 은 생략 가능)	\d{3,5} : 숫자가 3개, 4개 혹은 5개 있어야 함
\d		숫자 0 ~ 9					\d\d\d : 0 ~ 9 범위의 숫자가 3개를 의미 (123, 000 등)
\w		문자를 의미					\w\w\w : 문자가 3개를 의미 (xyz, ABC 등)
\s		화이트 스페이스를 의미하는데, [\t\n\r\f] 와 동일	\s\s : 화이트 스페이스 문자 2개 의미 (\r\n, \t\t 등)
.		뉴라인(\n) 을 제외한 모든 문자를 의미			.{3} : 문자 3개 (F15, 0x0 등)
"""
import re

#Ex>1
text = "에러 1122 : 레퍼런스 오류\n 에러 1033: 아규먼트 오류"
regex = re.compile("에러\s\d+")
mc = regex.findall(text)
print(mc)

#Ex>2
text = "문의사항이 있으면 032-232-3245 으로 연락주시기 바랍니다."
 
regex = re.compile(r'(\d{3})-(\d{3}-\d{4})')
matchobj = regex.search(text)
areaCode = matchobj.group(1)
num = matchobj.group(2)
fullNum = matchobj.group()
print(areaCode, num) # 032 232-3245