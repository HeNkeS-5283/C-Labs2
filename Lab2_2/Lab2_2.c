#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#pragma warning(disable : 4996)

struct Car
{
    char* brand;
    char* color;
    int number;
    int year;
    char* dataOwner;
};

struct BrandNum
{
    char* brand;
    int num;
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

    struct Car car[16] = {
        {"Nissan", "Red", 543216, 2011, "Man - 34 y."},
        {"Opel", "Blue", 847264, 1992, "Women - 25 y."},
        {"Nissan", "Yellow", 908463, 1999, "Man - 22 y."},
        {"Nissan", "Gray", 116523, 1997, "Women - 20 y."},
        {"Mazda", "White", 203944, 1998, "Women - 32 y."},
        {"Mazda", "Red", 539603, 2003, "Man - 32 y."},
        {"Opel", "Green", 726300, 2008, "Man - 56 y."},
        {"Mersedes", "Blue", 129304, 2016, "Women - 40 y."},
        {"Mersedes", "Gray", 745454, 2014, "Man - 45 y."},
        {"Mazda", "White", 232123, 2005, "Women - 26 y."},
        {"Nissan", "Yellow", 980665, 1987, "Man - 48 y."},
        {"Mersedes", "Green", 346643, 2000, "Women - 57 y."},
        {"Nissan", "Black", 323453, 1992, "Man - 55 y."},
        {"Nissan", "Gray", 657854, 2001, "Man - 32 y."},
        {"Lada", "Black", 112322, 2016, "Women - 46 y."},
        {"Mersedes", "Black", 116422, 2017, "Women - 46 y."}
    };
    int x = 0;
    int n = sizeof(car) / sizeof(car[0]);
    struct BrandNum brand['n'];

    for (int i = 0; i < n; i++) {
        brand[i].brand = car[i].brand;
        brand[i].num = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (brand[j].brand == car[i].brand) {
                brand[j].num++;
                break;
            }
        }
    }

    int* cars = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        if (brand[i].num != 0) {
            cars[x] = brand[i].num;
            x++;
        }
    }
    struct BrandNum brand2['x'];
    x = 0;
    for (int i = 0; i < n; i++) {
        if (brand[i].num != 0) {
            brand2[x].brand = brand[i].brand;
            brand2[x].num = brand[i].num;
            x++;
        }
    }
    cars = (int*)realloc(cars, x * sizeof(int));
    qsort(cars, x, sizeof(int), compare);

    printf("|---------------------------|\n");
    printf("| Рахунок марок автомобілів |\n");
    printf("|---------------------------|\n");
    printf("|  Марка \t| Кількість |\n");
    printf("|---------------|-----------|\n");
    for (int k = 0; k < x; k++)
    {
        for (int i = 0; i < x; i++) {
            if (cars[k] == brand2[i].num && brand2[i].brand != brand2[i - 1].brand) {
                printf("|  %s \t|     %d     |\n", brand2[i].brand, brand2[i].num);
                break;
            }
        }
    }
    printf("|---------------------------|\n");
    return 0;
}
