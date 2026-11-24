//f8 сумма элементов каждого столбца матрицы
//f14 определить количество элементов ниже k
//f29 сумма элементов столбцов  индекс которых находятся в заданном диапазоне k-m
#ifndef MATRIXFUNC
#define MATRIXFUNC
#include <stddef.h>
void cleanBuffer();
void setSize(int **matptr, size_t *rows, size_t *columns);
void fillMatrix(int **matptr, size_t rows, size_t columns);
void printMatrix(int **matptr, size_t rows, size_t columns);
void sumForEveryColumn(int **matptr, size_t rows, size_t columns, int *arrptr);
int countOfLessK(int **matptr, size_t rows, size_t columns, int k);
void sumOfColumnsKM(int **matptr, size_t rows, size_t columns, int *arrptr, size_t k, size_t m);

#endif 