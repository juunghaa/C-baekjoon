// 백준 25282번 
#include <stdio.h>
#include <stdlib.h>
// 1시간 쉬면 완전히 회복됨
// 1시간 = 60분 = 3600초니까
// 3600초 쉬는게 이득이려면 2의 12승 이상일때임! 즉 연속된 일이 12개 이상이면 쉴 것!
// 작업을 큰 것부터 일단 정렬하자
# define BREAK 3600LL
# define CASE 12
# define INF ((long long)4e18)

int cmp_desc(const void* a, const void *b) {
    return (*(int*)b-*(int*)a); // 내림차순 
}

static inline long long minll(long long a, long long b) {
    return a<b? a:b;
}

int main() {
    int n=0;
    if(scanf("%d", &n)!=1) return 0;

    //int* d = malloc(n*sizeof(int));
    int *d = (int*)malloc(sizeof(int)*(size_t)n);
    for(int i=0; i<n; i++) {
        scanf("%d", &d[i]);
    }
    qsort(d, (size_t)n, sizeof(int), cmp_desc);
    
    // 2의 제곱 미리 계산
    long long pow2[CASE+1];
    pow2[0]=1;
    for(int i=1; i<=CASE; i++) pow2[i]=pow2[i-1]*2LL;

    // dp는 작업 마쳤고 연속 카운트가 j일때 최소 비용 
    // ndp는 다음 작업 임시 계산 
    long long dp[CASE+1], ndp[CASE+1];

    for(int j=0; j<=CASE; j++) dp[j]=INF; // 무한대로 dp배열 초기화 
    dp[0]=0; 

    // 이제 메인 로직 시작 
    for(int i=0; i<n; i++) {
        for(int j=0; j<=CASE; j++) ndp[j]=INF; // 이것도 초기화 
        long long a = (long long)d[i]; // 현재 처리할 작업 비용 
        for (int j=0; j<=CASE; j++){
            if(dp[j]>=INF) continue; // 이전 상태가 불가능이면 건너뛰고 

            if(j<CASE){ // 연속 작업이 가능한 경우 
                long long cost_continue=dp[j]+a*pow2[j];
                ndp[j+1]=minll(ndp[j+1], cost_continue);
            }

            // 휴식하고 진행 
            long long cost_break=dp[j]+a+BREAK;
            ndp[1]=minll(ndp[1], cost_break);
        }
        for (int j=0; j<=CASE; j++){
            dp[j]=ndp[j];
        }    
    }

    // 모든 작업 끝나고 최소 찾기 
    long long result = INF;
    for(int i=0; i<=CASE; i++) {
        result = minll(result, dp[i]);
    }
    
    printf("%lld\n", result);
    free(d);
    return 0;
}