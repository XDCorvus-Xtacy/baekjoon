/*
문제
어떤 숫자 n이 자신을 제외한 모든 약수들의 합과 같으면, 그 수를 완전수라고 한다.
예를 들어 6은 6 = 1 + 2 + 3 으로 완전수이다.
n이 완전수인지 아닌지 판단해주는 프로그램을 작성하라.

입력
입력은 테스트 케이스마다 한 줄 간격으로 n이 주어진다. (2 < n < 100,000)
입력의 마지막엔 -1이 주어진다.

출력
테스트케이스 마다 한줄에 하나씩 출력해야 한다.
n이 완전수라면, n을 n이 아닌 약수들의 합으로 나타내어 출력한다(예제 출력 참고).
이때, 약수들은 오름차순으로 나열해야 한다.
n이 완전수가 아니라면 n is NOT perfect. 를 출력한다.

예제
6
12
28
-1

출력
6 = 1 + 2 + 3
12 is NOT perfect.
28 = 1 + 2 + 4 + 7 + 14
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//약수 구하기
int GetDivisors(int n, int divisors[])
{
    int count = 0;

    if (n <= 1) return 0;

    divisors[count++] = 1;  //1은 늘 약수

    for (int i=2; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            divisors[count++] = i;

            if (i != n/i)   //제곱수 방지
                divisors[count++] = n/i;
        }
    }

    return count;
}

//완전수 판별
int IsPerfect(int n, int divisors[], int count)
{
    int sum = 0;

    for (int i=0; i<count; i++)
        sum += divisors[i];

        return (sum == n);
}

//qsort() 매개함수
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}


//식 출력
void PrintEquation(int n, int divisors[], int count)
{
    printf("%d = ", n);

    for (int i=0; i < count; i++)
    {
        printf("%d", divisors[i]);
        if (i != count-1)
            printf(" + ");
    }
    printf("\n");
}

//메인 함수
int main(void)
{
    int nInput = 0;

    while (1)
    {
        //숫자 입력
        scanf("%d", &nInput);
        if (nInput == -1)
            break;

        int divisors[100000];
        int count = GetDivisors(nInput, divisors);

        //완전수 구하기
        if (IsPerfect(nInput, divisors, count))
        {
            qsort(divisors, count, sizeof(int), compare);
            PrintEquation(nInput, divisors, count);
        }
        else 
        {
            printf("%d is NOT perfect.\n", nInput);    
        }
    }
}