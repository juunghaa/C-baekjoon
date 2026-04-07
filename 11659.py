# 백준 11659번
# 시간 제한 0.5초
# 난이도 실버3

import sys
input = sys.stdin.readline
# N과 M 입력받기 
N, M = map(int, input().split())
# N개의 수 합 배열을 바로 입력받으며 동시에 구하기
numbers = list(map(int, input().split()))
sumlist = [0] # 파이썬의 리스트는 동적 배열이라 append ->메모리 공간을 추가하여 값을 저장해줌! 
temp = 0
for i in numbers:
    temp += i
    sumlist.append(temp)
# M개의 구간 합 구하기
for i in range(M):
    j, k = map(int, input().split())
    print(sumlist[k]-sumlist[j-1])
