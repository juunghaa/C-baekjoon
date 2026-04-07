# 백준 1546번
# 시간 제한 2초
# 난이도 브론즈1

# 과목 개수 N 입력받기
N = input()
# 리스트에 과목 점수 저장하기
scorelist = list(map(int, input().split()))
# 리스트를 탐색하며 점수의 최댓값 구하기
maxScore = max(scorelist)
# 리스트를 탐색하며 합 구하기
sum = sum(scorelist)
# 평균 구하기
average = sum/maxScore*100/int(N)
# 평균 출력하기
print(average)
