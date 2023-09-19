﻿// Merge_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include "sorting.h"

int cmp_func(float A, float B)
{
    if (A > B)
        return 1;
    if (A < B)
        return -1;
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int num = 20;
    float *arr = new float [num];

    for (int i = 0; i < num; i += 1)
        arr[i] = rand() % 10000;

    cout << "Начальный массив: ";
    for (int i = 0; i < num; i += 1)
        cout << arr[i] << "    ";
    cout << endl;

    float* s_arr = sorting <float> (arr, num, cmp_func);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < num; i += 1)
        cout << s_arr[i] << "    ";
    cout << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.