#include <stdio.h>
#include <stddef.h>
#include "matrixfunc.h"

#define MAX_ROWS 100
#define MAX_COLUMNS 100

int main(){
    int buffer[MAX_ROWS][MAX_COLUMNS];
    int arr[MAX_COLUMNS];
    int *arrrows[MAX_ROWS];

     for (int i = 0; i < MAX_ROWS; i++) {
          arrrows[i] = buffer[i]; 
     }
     int **matrix = arrrows; 
     int *array = arr;
     size_t rows = 0;
     size_t columns = 0;
     int isFilled = 0;
     char choice;
     
while(1){
     printf("a Задать размер матрицы (строки, столбцы)\n");
     printf("b Заполнить матрицу\n");
     printf("c Представление матрицы (значения, адреса элементов)\n");
     printf("d Вычислить сумму элементов для каждого столбца\n");
     printf("e Посчитать количество элементов меньше k\n");
     printf("f Вычислить сумму элементов столбцов k-m\n");
     printf("g Выход\n");
     printf("Введите команду: ");

     
     if (scanf("%c", &choice) != 1){
          printf("\nEOF or input error\n");
          return 0;
     }
     cleanBuffer();
     
     switch(choice){

          case 'a':
               setSize(matrix, &rows, &columns);
               break;

          case 'b':
               if (rows == 0 || columns == 0){
                    printf("\nРазмер не задан\n");
                    break;
               }
               fillMatrix(matrix, rows, columns);
               isFilled = 1;
               printf("\nМатрица заполнена\n");

               break;
          case 'c':
               if (rows == 0 || columns == 0){
                    printf("\nРазмер не задан\n");
                    break;
               }
               if (isFilled == 0){
                    printf("\nМатрица не заполнена\n");
                    break;
               }
               printMatrix(matrix, rows, columns);
               break;

          case 'd':
               if (rows == 0 || columns == 0){
                    printf("\nРазмер не задан\n");
                    break;
               }
               if (isFilled == 0){
                    printf("\nМатрица не заполнена\n");
                    break;
               }    
               sumForEveryColumn(matrix, rows, columns, array);
               for (int i = 0 ; i < columns; i++){
                    printf("Сумма значений в столбце %d - %d\n", i, *(array + i));
               }
               break;

          case 'e':
               if (rows == 0 || columns == 0){
                    printf("\nРазмер не задан\n");
                    break;
               }
               if (isFilled == 0){
                    printf("\nМатрица не заполнена\n");
                    break;
               }
               int k;
               printf("Введите k: ");
               if(scanf("%d", &k) != 1){
                    printf("\nEOF или ошибка ввода\n");
                    return 0;
               }
               cleanBuffer();
               printf("Количество значений меньше %d: %d\n", k, countOfLessK(matrix, rows, columns, k));
               break;       
          case 'f':
                  if (rows == 0 || columns == 0){
                    printf("\nРазмер не задан\n");
                    break;
               }
               if (isFilled == 0){
                    printf("\nМатрица не заполнена\n");
                    break;
               }
               size_t l;
               size_t m;
               printf("Введите значения k и m: ");
               if(scanf("%zu %zu", &l, &m) != 2){
                     printf("\nEOF или ошибка ввода\n");
               } 
               sumOfColumnsKM(matrix,  rows, columns, array, l, m);
               for (int i = 0 ; i < m - l + 1; i++){
                    printf("Сумма значений в столбце %d - %d\n", i, *(array + i));
               }
               cleanBuffer();
               break;
          case 'g':
               printf("\nВыход\n");
               return 0;
          default:
               printf("Неизвестная команда %c, выбирайте от a до g\n", choice);
               break;
     }
}
     return 0;
}