#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#pragma warning(disable : 4996)

void add(char* str, char* num) {
    FILE* file = fopen("D:\\file.txt", "w");
    fputs(str, file);
    fputs(num, file);
    fclose(file);
}

int main() {
    system("chcp 65001");
    setlocale(LC_CTYPE, "ukr");
    system("cls");

    FILE* file = fopen("D:\\file.txt", "r");

    if (file == NULL) {
        printf("�� ������� ������� ����.\n");
        return 1;
    }

    int n = 0;
    while ((fgetc(file)) != EOF) {
        n++;
    }
    char* num = (char*)calloc(100, sizeof(char*));
    fseek(file, 0, SEEK_SET);
    fgets(num, n + 1, file);
    fclose(file);

    printf("��� ������� � ����: %s", num);

    char* str = (char*)calloc(100, sizeof(char*));
    printf("\n������� ����� ���� ������ ���������� � ������� �����:\n");
    gets(str);

    add(str, num);

    printf("��� ������� ������!\n");
    free(num);
    free(str);
    return 0;
}
