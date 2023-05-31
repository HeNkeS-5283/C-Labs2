#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#pragma warning(disable : 4996)

int main(void)
{
	system("chcp 1251");
	setlocale(LC_CTYPE, "ukr");
	system("cls");
	FILE* file = fopen("D:\\111.txt", "r");

	if (file == NULL) {
		printf("Не вдалося відкрити файл.\n");
		return 1;
	}
	int n = 0, sum = 0, j;

	while ((fgetc(file)) != EOF) {
		n++;
	}
	char num['n' + 1];  // +1 для нуль-термінатора
	fseek(file, 0, SEEK_SET);  // повернення до початку файлу
	fgets(num, n + 1, file);
	printf("\nЧисла з файлу: %s ", num);
	char* token = strtok(num, " ");

	while (token != NULL) {
		sum += atoi(token);
		token = strtok(NULL, " ");
	}
	printf("\nСума чисел: %d \n", sum);

	fclose(file);
	return 0;
}
