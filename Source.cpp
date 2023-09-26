#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

                                                                // √енераци€ случайного массива заданной длины
int* generateRandomArray(int size) 
{
    int* array = new int[size];
    for (int i = 0; i < size; i++) 
    {
        array[i] = rand() % 9 + 1;                                  // —лучайное число от 1 до 9
    }
    return array;
}

                                                                // —ортировка массива по убыванию
void sortDescending(int* array, int size) 
{
    sort(array, array + size, greater<int>());
}

                                                                // —ортировка массива по возрастанию
void sortAscending(int* array, int size) 
{
    sort(array, array + size);
}

                                                                // √енераци€ и сортировка массивов
void generateAndSortArrays(int n) 
{
    srand(time(0));                                             // »нициализируем генератор случайных чисел

    int** arrays = new int* [n];                                // —оздаем массив указателей на массивы
    int* usedSizes = new int[n];                                // ћассив дл€ хранени€ использованных размеров

    for (int i = 0; i < n; i++) 
    {
        int size;
        do 
        {
            size = rand() % 15 + 1;                            // √енерируем случайный размер массива от 1 до 15
        } while (find(usedSizes, usedSizes + i, size) != usedSizes + i); // ѕровер€ем, что размер не повтор€етс€

        usedSizes[i] = size;
        arrays[i] = generateRandomArray(size);


                                                                // —ортируем массивы с четным пор€дковым номером по возрастанию,
                                                                // а с нечетным - по убыванию
        if (i % 2 == 0) 
        {
            sortAscending(arrays[i], size);
        }
        else {
            sortDescending(arrays[i], size);
        }

                                                                // ¬ыводим отсортированный массив на экран
        for (int j = 0; j < size; j++) {
            cout << arrays[i][j] << " ";
        }
        cout << endl;

        delete[] arrays[i];                                     // ќсвобождаем пам€ть дл€ каждого массива
    }



    delete[] arrays;                                            // ќсвобождаем массив указателей
    delete[] usedSizes;                                         // ќсвобождаем массив использованных размеров
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "¬ведите количество массивов (n): ";
    cin >> n;

    generateAndSortArrays(n);

    return 0;
}