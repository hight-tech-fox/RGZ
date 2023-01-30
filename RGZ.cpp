/*По заданной квадратной матрице размером 10*10 построить вектор длиной 19, 
эле-менты которого – максимумы элементов диагоналей, 
параллельных главной диагонали.*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	const int size = 10; // размерность
	int mass[size][size]; // массив 10*10
	int vector[2 * size - 1]; // вектор максимумов
	int maxl; // переменная для поиска максимумов
	int n;

	srand(time(NULL)); //заполнение массива случайными числами
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			n = rand() % 10;
			mass[i][j] = n;
		}
	}
	//printf("Введите массив\n");
	//for (int i = 0; i < size; i++) { //заполняем массив вручную
		//for (int j = 0; j < size; j++) {
			//scanf_s("%d", &mass[i][j]);
		//}
	//}

	for (int i = 0; i < size; i++) { //вывод значений
		for (int j = 0; j < size; j++) {
			printf("%d\t", mass[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int l = 0; l < 2 * size; l++) { // кол-во диагоналей
		if (l <= size) { // идем из левого нижнего угла до главной диагонали
			maxl = mass[size - l][0];
			for (int i = size - l; i < size; i++) {
				if (mass[i][i - size + l] > maxl) {
					maxl = mass[i][i - size + l];
				}
				vector[l] = maxl;
			}
		}
		else {
			if (l > size) { // идем вправо до правого верхнего угла
				maxl = mass[0][l - size];
				for (int i = -1; i < 2 * size - l; i++) {
					if (mass[i][i + l - size] > maxl) {
						maxl = mass[i][i + l - size];
					}
					vector[l] = maxl;
				}
			}
		}
	}
	printf("Максимальные элементы диагоналей, параллельных главной:\n");
	for (int i = 1; i < 2 * size; i++) {
		printf("%d\t", vector[i]);
	}
	return 0;
}
