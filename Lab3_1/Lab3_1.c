#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#pragma warning(disable : 4996)


int setn() {
	int n, x = 0, y;
	while (x != 1) {
		x = 1;
		system("cls");
		printf("Введiть кiлькiсть чисел для задачі (мінімум 2): ");
		printf("\nn = ");
		scanf("%d", &y);
		if (y >= 2) n = y;
		else x = 0;
	}
	return n;
}

void set_arr(int n, float* a) {
	int x = 0, y;
	while (x != 1)
	{
		x = 1;
		printf("\nВвести від'ємні числа для задачі:\n");
		for (int i = 0; i < n; i++)
		{
			printf("x[%d] = ", i+1);
			scanf("%d", &y);
			if (y >= 0) {
				system("cls");
				printf("Введене не від'ємне число спробуйте знову.");
				x = 0;
				break;
			}
			else { 
				a[i] = (float)y;
			}
		}
	}
}

float act(int n, float* a) {
	if (n == 0) return 0;
	else return (a[n-1]/a[n] + act(n-1, a));
}

int main() {
	system("chcp 1251");
	setlocale(LC_CTYPE, "ukr");
	system("cls");

	int n = setn();
	float* a = (float*)malloc(n * sizeof(float));
	set_arr(n, a);
	float result = act(n - 1, a);
	printf("\nРезультат: %.2f", result);
	free(a);

	return 0;

}
