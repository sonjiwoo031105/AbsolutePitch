#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <time.h>

#define SIZE 7
void pr_str_array(char** dp, int n);
int main(void)
{
    char* p[SIZE] = { "��", "��", "��", "��", "��" , "��", "��" };
    pr_str_array(p, SIZE);
    return 0;
}
void pr_str_array(char** dp, int n)
{
    srand((unsigned int)time(NULL));
    int random = (rand() % 7);

    printf("%d��° ���ڿ� : %s\n", random, *(dp + random));

    char answer[10];

    printf("������ �����ϱ��?: ");
    scanf("%s", answer);

    if (!strcmp(answer, *(dp + random))) {
        printf("�¾ҽ��ϴ�.\n");
    }
    else {
        printf("Ʋ�Ƚ��ϴ�."); \
    }

}