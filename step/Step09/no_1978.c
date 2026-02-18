/*
문제
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

입력
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 
다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

출력
주어진 수들 중 소수의 개수를 출력한다.

예제 입력 1 
4
1 3 5 7
예제 출력 1 
3
*/

#include <stdio.h>

//소수 판별 함수
int IsPrime(int n)
{
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n%2 == 0)    return 0;

    for (int i = 3; i*i <= n; i += 2)
    {
        if (n%i == 0)
            return 0;
    }

    return 1;
}

int main(void)
{
    //Test 수 입력
    int nInput = 0;
    scanf("%d", &nInput);

    //소수 구하기 위한 변수 선언 및 정의
    int n = 0;
    int count = 0;

    //소수 개수 구하기
    for (int i=0; i < nInput; i++)
    {
        scanf("%d", &n);
        if (IsPrime(n))
            count++;
    }

    //소수 개수 출력
    printf("%d\n", count);
    return 0;
}