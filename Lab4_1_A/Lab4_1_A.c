#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
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
		printf("����i�� �i���i��� ����� ��� ������: ");
		printf("\nn = ");
		if (scanf("%d", &n) != 1 || n <= 0) {
			x = 0;
			while (getchar() != '\n');  // ������� ������ ��������
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

void set_arr(int n, int* a) {
	printf("\n������ �i���i ����� ��� ������:\n");
	for (int i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	system("cls");
	printf("\n������� �����:\n");
	printf("� = {");
	for (int i = 0; i < n; i++)
	{
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
	printf("\n����� � ���������� � 2 ���� ������� ���������� ");
	printColorT("(�������� ����)", "\x1b[31m");
	printf(" � ��������� �������� �������� �������� �� ��������� ");
	printColorT("(���� ����)", "\x1b[34m");
	printf(".\n");
	printf("a = { ");
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0)
			printColor(a[i], "\x1b[31m");  // �������� ���� ��� ������ ��������
		else
			printColor(a[i], "\x1b[34m");  // ���� ���� ��� �������� ��������
		printf(", ");
	}
	printf("}\n");
}

int main() {
	system("chcp 1251");
	setlocale(LC_CTYPE, "ukr");
	system("cls");

	int n = setn();
	float* a = (float*)malloc(n * sizeof(float));
	set_arr(n, a);
	act(a, n);

	free(a);

	return 0;

}