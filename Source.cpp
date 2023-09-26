#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

                                                                // ��������� ���������� ������� �������� �����
int* generateRandomArray(int size) 
{
    int* array = new int[size];
    for (int i = 0; i < size; i++) 
    {
        array[i] = rand() % 9 + 1;                                  // ��������� ����� �� 1 �� 9
    }
    return array;
}

                                                                // ���������� ������� �� ��������
void sortDescending(int* array, int size) 
{
    sort(array, array + size, greater<int>());
}

                                                                // ���������� ������� �� �����������
void sortAscending(int* array, int size) 
{
    sort(array, array + size);
}

                                                                // ��������� � ���������� ��������
void generateAndSortArrays(int n) 
{
    srand(time(0));                                             // �������������� ��������� ��������� �����

    int** arrays = new int* [n];                                // ������� ������ ���������� �� �������
    int* usedSizes = new int[n];                                // ������ ��� �������� �������������� ��������

    for (int i = 0; i < n; i++) 
    {
        int size;
        do 
        {
            size = rand() % 15 + 1;                            // ���������� ��������� ������ ������� �� 1 �� 15
        } while (find(usedSizes, usedSizes + i, size) != usedSizes + i); // ���������, ��� ������ �� �����������

        usedSizes[i] = size;
        arrays[i] = generateRandomArray(size);


                                                                // ��������� ������� � ������ ���������� ������� �� �����������,
                                                                // � � �������� - �� ��������
        if (i % 2 == 0) 
        {
            sortAscending(arrays[i], size);
        }
        else {
            sortDescending(arrays[i], size);
        }

                                                                // ������� ��������������� ������ �� �����
        for (int j = 0; j < size; j++) {
            cout << arrays[i][j] << " ";
        }
        cout << endl;

        delete[] arrays[i];                                     // ����������� ������ ��� ������� �������
    }



    delete[] arrays;                                            // ����������� ������ ����������
    delete[] usedSizes;                                         // ����������� ������ �������������� ��������
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "������� ���������� �������� (n): ";
    cin >> n;

    generateAndSortArrays(n);

    return 0;
}