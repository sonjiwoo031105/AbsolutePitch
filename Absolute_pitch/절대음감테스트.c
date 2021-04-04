#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <time.h>

#define SIZE 7
void pr_str_array(char** dp, int n);
int main(void)
{
    char* p[SIZE] = { "도", "레", "미", "파", "솔" , "라", "시" };
    pr_str_array(p, SIZE);
    return 0;
}
void pr_str_array(char** dp, int n)
{
    srand((unsigned int)time(NULL));
    int random = (rand() % 7);

    printf("%d번째 문자열 : %s\n", random, *(dp + random));

    char answer[10];

    printf("정답은 무엇일까요?: ");
    scanf("%s", answer);

    if (!strcmp(answer, *(dp + random))) {
        printf("맞았습니다.\n");
    }
    else {
        printf("틀렸습니다."); \
    }

}