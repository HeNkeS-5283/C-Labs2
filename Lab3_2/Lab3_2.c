#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#pragma warning(disable : 4996)

float combination(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return combination(n - 1, k - 1) + combination(n - 1, k);
}

int main() {
    system("chcp 1251");
    setlocale(LC_CTYPE, "ukr");
    system("cls");
    printf("Завдання:\nІз шести бігунів і трьох стрибунів треба скласти команду із 4 чоловік, в яку б входив хоч би один стрибун. Скількома способами це можна зробити?\n");
    int res = combination(6,3)*combination(3, 1)+combination(6, 2)* combination(3, 2)+ combination(6, 1)* combination(3, 3);
    printf("\nВідповідь: %d способами можна скласти команду.", res);
    return 0;
}