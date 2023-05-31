#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

void printColor(int num, const char* color) {
	printf("%s%d%s", color, num, "\x1b[0m");
}

void printColorF(float num, const char* color) {
	printf("%s%.2f%s", color, num, "\x1b[0m");
}

int setn() {
	int n, x = 0;
	while (x != 1) {
		x = 1;
		system("cls");
		printf("����i�� �i���i��� ����i� ������: ");
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

int setm() {
	int m, x = 0;
	while (x != 1) {
		x = 1;
		system("cls");
		printf("����i�� �i���i��� ��������i� ������: ");
		printf("\nm = ");
		if (scanf("%d", &m) != 1 || m <= 0) {
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
	return m;
}

void set_arr(int n, int m, int** a) {
	printf("\n����i�� �i�i ����� ��� ������:");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			printf("\nA[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	system("cls");
	printf("������� ����� %dx%d\n", n, m);
	printf("A = ");
	for (int i = 0; i < n; i++) {
		printf("\t{");
		for (int j = 0; j < m; j++) {
			printf("\t%d,", a[i][j]);
		}
		printf("\t}\n");
	}
}

void act(int n, int m, int** a) {
	int min = a[0][0], max = a[0][0];
	float res;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (min > a[i][j]) min = a[i][j];
			if (max < a[i][j]) max = a[i][j];
		}
	}
	printf("\n����������� ����� - ");
	printColor(max, "\x1b[31m");
	printf("\n̳������� ����� - ");
	printColor(min, "\x1b[36m");
	res = (float)(max + min) / 2;
	printf("\n\n������ ����������� ���������� � ������������� ����� - ");
	printColorF(res, "\x1b[33m");
	printf("\n");
}

int main() {
	system("chcp 1251");
	setlocale(LC_CTYPE, "ukr");
	system("cls");

	int n = setn();
	int m = setm();
	int** a = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(m * sizeof(int)); // �������� ���'�� ��� ������� �����
	}

	set_arr(n, m, a);
	act(n, m, a);

	for (int i = 0; i < n; i++) {
		free(a[i]); // ��������� ���'�� ��� ������� �����
	}
	free(a);

	return 0;

}