#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996)

void printColor(int num, const char* color) {
	printf("%s%d%s", color, num, "\x1b[0m");
}

void printColorT(char* text, const char* color) {
	printf("%s%s%s", color, text, "\x1b[0m");
}

int setn() {
	int n, x = 0;
	while (x != 1) {
		x = 1;
		system("cls");
		printf("Введiть кiлькiсть чисел для задачі: ");
		printf("\nn = ");
		if (scanf("%d", &n) != 1 || n <= 0) {
			x = 0;
			while (getchar() != '\n');  // Очистка буфера введення
		}
		else {
			char c;
			while ((c = getchar()) != '\n') {
				if (!isdigit(c)) {
					x = 0;
					break;
				}
			}
		}
	}
	return n;
}

void arr_rand(int n, int* a) {
	const int Low = -100, High = 100;
	srand(time(0));

	printf("\nЗгенерований масив:\n");
	printf("a = {");
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (High - Low + 1) + Low;
		printf(" %d, ", a[i]);
	}
	printf("}\n");
}

void act(int* a, int n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) a[i] *= 2;
		if (a[i] % 2 != 0) a[i] *= -1;
	}
	printf("\nМасив з збільшеними у 2 рази парними елементами ");
	printColorT("(Червоний колір)", "\x1b[31m");
	printf(" і заміненими значення непарних елементів на протилежні ");
	printColorT("(Синій колір)", "\x1b[34m");
	printf(".\n");
	printf("a = { ");
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0)
			printColor(a[i], "\x1b[31m");  // Червоний колір для парних елементів
		else
			printColor(a[i], "\x1b[34m");  // Синій колір для непарних елементів
		printf(", ");
	}
	printf("}\n");
}

int main() {
	system("chcp 1251");
	setlocale(LC_CTYPE, "Ukrainian");
	system("cls");

	int n = setn();
	int* a = (int*)malloc(n * sizeof(int));
	arr_rand(n, a);
	act(a, n);

	free(a);

	return 0;
}