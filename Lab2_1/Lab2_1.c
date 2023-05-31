#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#pragma warning(disable : 4996)

struct Book
{
    char* bAuthor;
    char* bName;
    int year;
    char group;
};

// Функція порівняння для qsort
int compare(const void* a, const void* b) {
    // Приведення типів з void* до int*
    const int* num1 = (const int*)a;
    const int* num2 = (const int*)b;

    if (*num1 < *num2) {
        return -1;
    }
    else if (*num1 > *num2) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    system("chcp 65001");
    setlocale(LC_CTYPE, "ukr");
    system("cls");

    struct Book book[3] = {
        {"Дойль", "Сумчасті", 1990, 'C'},
        {"Сенкевич", "Потоп", 1978, 'X'},
        {"Ландау", "Механіка", 1989, 'Y'}
    };
    printf("|-------------------------------------------------------|\n");
    printf("| Каталог бібліотеки \t\t\t\t\t|\n");
    printf("|-------------------------------------------------------|\n");
    printf("| Автор книги \t| Назва \t| Рік видання \t| Група |\n");
    printf("|---------------|---------------|---------------|-------|\n");
    int years[] = { book[0].year, book[1].year, book[2].year };
    qsort(years, 3, sizeof(int), compare);
    for (int k = 0; k < 3; k++)
    {
        for (int i = 0; i < 3; i++) {
            if (years[k] == book[i].year)
                printf("| %s \t| %s \t|     %d\t|   %c\t|\n", book[i].bAuthor, book[i].bName, book[i].year, book[i].group);
        }
    }
    printf("|-------------------------------------------------------|\n");
    printf("| Зауваження: \t\t\t\t\t\t|\n| Х - художня література; У - навчальна література;\t|\n| С - довідкова література \t\t\t\t|\n");
    printf("|-------------------------------------------------------|\n");
    return 0;
}
