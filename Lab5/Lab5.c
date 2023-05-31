#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996)

void printColor(int num, const char* color) {
	printf("%s%d%s", color, num, "\x1b[0m");
}

void act() {
	const int Low = -100, High = -1;
	srand(time(0));
	int sum = 0;
	int n = rand() % 50 + 1;
	int* a = (float*)malloc(n * sizeof(float));

	system("cls");
	printf("\nЗгенерований масив:\n");
	printf("a = {");
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (High - Low + 1) + Low;
		printf(" %d, ", a[i]);
		sum += a[i];
	}
	printf("}\n");
	printf("\nКількість елементів масиву - ");
	printColor(n, "\x1b[33m");
	printf("\nСумма чисел масиву - ");
	printColor(sum, "\x1b[36m");
	printf("\n\n");
	free(a);
}


int main() {
	system("chcp 1251");
	setlocale(LC_CTYPE, "ukr");
	system("cls");
	char d = 'A';
	while (d != 'N') {
		printf("Згенерувати новий масив (Y or N):");
		scanf(" %c", &d);
		if (d == 'Y') {
			act();
		} 
	}

	return 0;
}