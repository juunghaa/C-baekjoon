# 백준 11720번

# N을 입력받기
N = int(input())
# 변수로 공백없는 숫자들을 입력받는다
numbers = list(input())
# 합 변수 선언
sum = 0
# for문으로 숫자들을 하나씩 탐색
for i in numbers:
    # 합변수에 숫자 더하기
    sum += int(i)
# 합 출력 
print(sum)
