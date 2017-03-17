#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<Windows.h>

void judge(int judgeNum, int* i);
void zero(char judgeName1[], int i, int array[], char nickName[][50], int M);

int main(int argc, char const* argv[])
{
	int M;//转发总量<=1000
	int N;//中奖间隔
	int S;//第一位中奖者序号
	int judgeNum = 0;
	char nickName[1000][50];//转发者昵称
	int array[1000];
	int i = 0;
	char* judgeName1;
	judgeName1 = (char*)malloc(sizeof(char) * 50);

	scanf_s("%d %d %d", &M, &N, &S);
	getchar();

	for (i = 0; i < M; i++)
	{
		scanf_s("%s", &nickName[i], 50);
		getchar();
		array[i] = 1;
	}

	i = S - 1;
	for (i; i < M;)
	{
		if (i > M - 1)
		{
			printf("Keep going...\n");
			break;
		}

		//判断是否出现过
		judgeNum = array[i];
		judge(judgeNum, &i);

		printf("%s\n", nickName[i]);

		//将出现过的昵称的array全变成-1
		strcpy_s(judgeName1, 50, nickName[i]);
		zero(judgeName1, i, array, nickName, M);

		i += N;
	}

	if (i >= M && i == S - 1)
	{
		printf("Keep going...\n");
	}

	free(judgeName1);

	system("pause");
	return 0;
}

void zero(char judgeName1[], int i, int array[], char nickName[][50], int M)
{
	char* judgeName2;
	judgeName2 = (char*)malloc(sizeof(char) * 50);

	for (i; i < M; i++)
	{
		if (*(array + i) == -1)//若这个昵称早已变成-1就跳过
			continue;

		strcpy_s(judgeName2, 50, nickName[i]);
		if (strcmp(judgeName1, judgeName2) == 0)
		{
			*(array + i) = -1;
		}
	}

	free(judgeName2);
}

void judge(int judgeNum, int* i)
{
	if (judgeNum == -1)
		*i += 1;
}