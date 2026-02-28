#include <stdio.h>
// 사각형의 모양과 넓이에 따라 서로 다른 점수를 얻음
// a=최소 넓이
// 넓이가 정확히 a인 볼록사각형은 4점 오목 사각형은 3점
// 넓이가 a보다 크면 볼록 사각형 2점 오목 사각형 1점 

int calculate_area(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    // 사각형 넓이 계산 (대각선로 나누어 계산)
    int area1 = abs(x1*y2 + x2*y3 + x3*y4 + x4*y1 - (y1*x2 + y2*x3 + y3*x4 + y4*x1));
    return area1 / 2; // 실제 넓이 반환
}

// 1. 세 점의 방향을 판별하는 CCW 함수 (외적 공식)
long long ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    // 결과가 양수면 반시계(좌회전), 음수면 시계(우회전), 0이면 일직선
    long long res = (long long)(x2 - x1) * (y3 - y1) - (long long)(x3 - x1) * (y2 - y1);
    
    if (res > 0) return 1;  
    if (res < 0) return -1; 
    return 0;               
}

// 2. 점 P가 삼각형(A, B, C) 안에 갇혀있는지 확인하는 함수
int is_inside_triangle(int ax, int ay, int bx, int by, int cx, int cy, int px, int py) {
    long long c1 = ccw(ax, ay, bx, by, px, py);
    long long c2 = ccw(bx, by, cx, cy, px, py);
    long long c3 = ccw(cx, cy, ax, ay, px, py);

    // 점 P가 삼각형의 세 변을 기준으로 모두 같은 방향(전부 반시계 or 전부 시계)에 있으면 내부!
    if ((c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0)) {
        return 1; // 삼각형 안에 갇힘!
    }
    return 0; // 밖에 있음
}

// 3. 4개의 점이 볼록 사각형인지 확인하는 메인 로직
int is_convex(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    // 4개의 점 중 '단 하나라도' 나머지 3개로 만든 삼각형 안에 들어가면 오목 사각형!
    if (is_inside_triangle(x1, y1, x2, y2, x3, y3, x4, y4)) return 0; // 4번 점이 갇힘
    if (is_inside_triangle(x1, y1, x2, y2, x4, y4, x3, y3)) return 0; // 3번 점이 갇힘
    if (is_inside_triangle(x1, y1, x3, y3, x4, y4, x2, y2)) return 0; // 2번 점이 갇힘
    if (is_inside_triangle(x2, y2, x3, y3, x4, y4, x1, y1)) return 0; // 1번 점이 갇힘

    return 1; // 아무도 안 갇혔으면 완벽한 '볼록 사각형'입니다!
}

int main() {
    // 첫줄에 정수 n은 점의 개수로 4이상 1000이하
    int n=0;
    if(scanf("%d", &n)!=1) return 0;

    int* points = (int*)malloc(sizeof(int)*(size_t)(n*2));
    // 다음 n줄에는 각각 두 정수가 주어지며 한 점의 좌표를 나타냄
    // 좌표 값은 -10의9승 이상 10의9승 이하임 
    for(int i=0; i<n; i++) {
        scanf("%d %d", &points[i*2], &points[i*2+1]);
    }
    // 이제 점들을 이용해 사각형을 만들고 넓이를 계산
    // 사각형을 만들려면 4개 점 필요
    // 선택 가능한 모든 4점 조합
    // n은 전체 점의 개수, pts는 점들의 좌표가 담긴 배열이라고 가정
    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            for (int k = j + 1; k < n - 1; k++) {
                for (int l = k + 1; l < n; l++) {
                    // 이렇게 하면 i, j, k, l 인덱스가 모두 다른 4개의 점이 선택됨
                    // 1번째 점 (i번 점)
                    int x1 = points[2 * i];
                    int y1 = points[2 * i + 1];
                    
                    // 2번째 점 (j번 점)
                    int x2 = points[2 * j];
                    int y2 = points[2 * j + 1];
                    
                    // 3번째 점 (k번 점)
                    int x3 = points[2 * k];
                    int y3 = points[2 * k + 1];
                    
                    // 4번째 점 (l번 점)
                    int x4 = points[2 * l];
                    int y4 = points[2 * l + 1];
                    
                    // 사각형 모양 검사 
                    if ((x1, y1, x2, y2, x3, y3, x4, y4)) {
                        // 사각형 발견!
                    }
                }
            }
        }
    }

    // 사각형을 만들 수 있는 모든 조합을 고려해야 함
    // 사각형의 넓이를 계산하는 함수 필요
    // 사각형이 볼록인지 오목인지 판단하는 함수 필요
    // 최소 넓이를 찾아서 점수를 계산
    int total_score = 0;
    
    // 최종 점수를 출력
    printf("%d\n", total_score);

    free(points);
    return 0;
    // 출력값은 최대 총 점수..
}