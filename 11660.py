# 백준 11660번
# 시간 제한 1초

# n, m
# n
# m 
# 합 출력 

import sys

# 입력 받기 N, M
input = sys.stdin.readline
n, m = map(int, input().split())

# 배열 초기화
A = [[0]*(n+1)]
S = [[0]*(n+1) for _ in range(n+1)]

# N만큼 반복해서 입력받기 -> 리스트에 넣기 A 와 동시에 구간합 배열 S 만들기 
# 구간 합 공식 S[i][j] = S[i][j-1] + A[i][j]
# 구간 합 사각형 만들기 공식 S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j]
for i in range(1, n+1):
    row = list(map(int, input().split()))
    A.append([0] + row)

    for j in range(1, n+1):
        S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j]

# M만큼 반복해서 입력받기 -> 리스트에 넣어두기 m_list
# 구간 합 구하기 <- M만큼 반복 
# 공식 Sum(x1, y1, x2, y2) = S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1]
# 출력하기 
for i in range(m):
    x1, y1, x2, y2 = list(map(int, input().split()))
    Sum = S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1]
    print(Sum)
    
