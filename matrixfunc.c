#include "matrixfunc.h"
#include <stddef.h>
#include <stdio.h>
#define MAX_ROWS 100
#define MAX_COLUMNS 100
void cleanBuffer(){
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}
void setSize(int **matptr, size_t *rows, size_t *columns){
    printf("Введите количество строк (1-%d) и столбцов (1-%d): ", MAX_ROWS,MAX_COLUMNS);
                int input = scanf("%zu %zu", rows, columns);
                if (input == EOF){
                    printf("\nEOF\n");
                    return ;
                }
                    cleanBuffer();

                if (input != 2 || rows == 0 || columns == 0 || *rows > MAX_ROWS || *columns > MAX_COLUMNS){
                    printf("\nНеверный размер\n");
                    rows = 0;
                    columns = 0;
                   return;
                }
                for(size_t i = 0 ; i < *rows ; i++){
                    for (size_t j = 0 ; j < *columns; j++){

                    *(matptr[i] + j) = 0;
                    }
                }
                printf("\nРазмер матрицы: %zu х %zu\n", *rows, *columns);
             
}

void fillMatrix(int **matptr, size_t rows, size_t columns){
 if (matptr == NULL || rows == 0 || columns == 0){
        printf("Матрица не создана или ее размеры не заданы\n");
        return ;
    }

    for (size_t i = 0 ; i < rows ; i++){
        for (size_t j = 0 ; j < columns ; j++){
            while(1){
                printf("Введите значение элемента [%zu][%zu]: ", i, j);
                int res = scanf("%d", matptr[i] + j);
                if(res == EOF){
                    printf("\nEOF\n");
                    return;
                }
                if (res == 1){
                    cleanBuffer();
                    break;
                }
                printf("Неверный формат\n");
                cleanBuffer();
            }
        }
    }
}
void printMatrix(int **matptr, size_t rows, size_t columns){
    if (matptr == NULL || rows == 0 || columns == 0){
        printf("Матрица не создана или ее размеры не заданы\n");
        return ;
    }
    printf("\nИндекс стр | Индекс стл | Значение     | Адрес ");
    for (size_t i = 0 ; i < rows ; i++){
        for (size_t j = 0 ; j < columns ; j++){
            printf("\n%10zu | %10zu | %12d | %p\n", i, j, *(matptr[i] + j), (void *)(matptr[i] + j));
        }
    }
}
void sumForEveryColumn(int **matptr, size_t rows, size_t columns,  int *arrptr){
     if (matptr == NULL || rows == 0 || columns == 0 || arrptr == NULL){
        printf("Матрица не создана или ее размеры не заданы\n");
        return ;
    }
    int c = 0;
    for (size_t i = 0; i < columns ; i++){
        for(size_t j = 0 ; j < rows; j++){
            c += *(matptr[j] + i);
        }    
        *(arrptr + i) = c;
        c = 0;
    }
}
int countOfLessK(int **matptr, size_t rows, size_t columns, int k){
    if (matptr == NULL || rows == 0 || columns == 0){
        printf("Матрица не создана или ее размеры не заданы\n");
        return -1;
    }
    int c = 0;
    for (size_t i = 0 ; i < rows ; i++){
        for (size_t j = 0 ; j < columns ; j++){
            if (*(matptr[i] + j ) < k){
                c++;
            }
        }
    }
    return c;
}
void sumOfColumnsKM(int **matptr, size_t rows, size_t columns, int *arrptr, size_t k, size_t m){
    if (matptr == NULL || rows == 0 || columns == 0 || arrptr == NULL) {
        printf("Матрица не создана или ее размеры не заданы\n");
        return ;
    }
    if ( m < k || m >= columns){
        printf("неверные индексы\n");
        return ;
    }
    int sum = 0;
    int arrindex = 0;
        for (size_t x = k ; x <= m ; x++){
            for (size_t y = 0 ; y < rows; y++){
                sum += *(matptr[y] + x);
            }
            *(arrptr + arrindex ) = sum;
            arrindex++;
            sum = 0;
        }
    
}