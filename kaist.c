#include <stdio.h>
#include <stdlib.h>

#define Maxstring 127

struct Timelist
{
    int date;
    int time;
    int important;
    char name[Maxstring];
    char details[Maxstring];
};

struct Timelist input()
{
    struct Timelist t;
    scanf("%d", &t.date);
    scanf("%d", &t.time);
    scanf("%d", &t.important);
    scanf("%s", t.name);
    scanf("%s", t.details);
    return t;
}

void supperprint(struct Timelist *copyt, int n)
{
    for (int i = 0; i < n; i++)
    {
        int y = copyt[i].date / 10000;
        int m = copyt[i].date / 100 - y * 100;
        int d = copyt[i].date - (y * 10000 + m * 100);
        int H = copyt[i].time / 100;
        int h = copyt[i].time % 100;
        printf("%.4d.", y);                // 년
        printf("%.2d.", m);                // 월
        printf("%.2d ", d);                // 일
        printf("%.2d:", H);                // 시간
        printf("%.2d ", h);                // 분
        printf("%d ", copyt[i].important); // 중요도
        printf("%s ", copyt[i].name);      // 제목
        printf("%s \n", copyt[i].details); // 디테일
    }
}

int main()
{
    int howmany;
    scanf("%d", &howmany);

    // 동적 메모리 할당
    struct Timelist *copyt = malloc(howmany * sizeof(struct Timelist));

    for (int i = 0; i < howmany; i++)
    {
        copyt[i] = input(); // 저장하는 함수
    }

    supperprint(copyt, howmany); // 출력하는 함수

    // 메모리 해제
    free(copyt); // 솔직히 그렇게 큰 의미가 있는지 잘 모르겠다

    return 0;
}