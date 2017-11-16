#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

struct point
{
	float x, y;
};

struct vec
{
	float x, y;
};

float dl(float x, float y){return sqrt(x*x + y*y);}  //вычисляем длину вектора

int main()
{
	const float eps = 0.0000001;
	point a[4];
	vec b[6];
	float c[6];
	short k=0;
	while (k!=1)
	{
		for (int i = 0; i <= 3; i++)              //считываем точки с координатами x и y
		{
			cout << "Enter x and y " << i + 1 << " point" << endl;
			cin >> a[i].x >> a[i].y;
		}
		/*Вычисляем координаты векторов, проходящих через 2 точки*/
		b[0].x = a[1].x - a[0].x;                
		b[0].y = a[1].y - a[0].y;

		b[1].x = a[2].x - a[1].x;
		b[1].y = a[2].y - a[1].y;

		b[2].x = a[3].x - a[1].x;
		b[2].y = a[3].y - a[1].y;

		b[3].x = a[2].x - a[3].x;
		b[3].y = a[2].y - a[3].y;

		b[4].x = a[2].x - a[0].x;
		b[4].y = a[2].y - a[0].y;

		b[5].x = a[3].x - a[0].x;
		b[5].y = a[3].y - a[0].y;
		/*Конец вычислений координат векторов*/

		for (int i = 0; i <= 5; i++) c[i] = dl(b[i].x, b[i].y);  //вычисляем длину каждого вектора и записываем результат в массив

		/*Сортируем массив с длинами векторов в порядке возрастания*/
		for (int i = 5; i >= 0; i--)
			for (int j = 0; j < i; j++)
			{
				if (c[j] > c[j + 1])
				{
					float tmp = c[j];
					c[j] = c[j + 1];
					c[j + 1] = tmp;
				}
			}
		/*Конец сортировки*/

		cout << "Length of sides: ";
		for (int i = 0; i <= 5; i++)    //вывод отсортированного массива
			cout << c[i] << " ";
		if (c[0] != 0 && c[1] != 0 && c[2] != 0 && c[3]!=0 && c[4]!=0 && c[5]!=0)
		if (c[0] == c[1] && c[1] == c[2] && c[2] == c[3] && ((c[4] - c[5]) < eps)) cout << endl << "Yes, it is a square" << endl;  //проверка на на квадрат
		else
			cout << endl << "No, it's not a square" << endl;
		else
			cout << endl << "No, it's not a square" << endl;
		cout << "Enter 1 to exit or enter 2 to continue: ";
		cin >> k;
		cout << endl;
	}
	
	return 0;
}