#include <iostream>
#include <string>
 
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    srand(time(NULL));

    //Контрольная работа № 1
    //16.	Сравнить суммы элементов диагоналей двумерного массива

    int rows = 2 + rand() % 5;
    int cols = 2 + rand() % 5;

    cout << "Массив" << "[" << rows << ", " << cols << "]";
    cout << "\n\r";

    cout << "\n\r";

    int** arr = new int* [rows];

    for (int i = 0; i < rows; ++i) 
    {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; ++j) 
        {
            arr[i][j] = 1 + rand() % 20;
        }
    }

    int sumMainDiagonal = 0;
    int sumSecondaryDiagonal = 0;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (i == j)
                sumMainDiagonal += arr[i][j];

            if (j == cols - 1 - i)
                sumSecondaryDiagonal += arr[i][j];

            cout << arr[i][j] << "\t";
        }
        cout << "\r\n";
    }

    string result = "";

    if (sumMainDiagonal > sumSecondaryDiagonal)
    {
        result = "больше";
    }
    else if (sumMainDiagonal < sumSecondaryDiagonal)
    {
        result = "меньше";
    }
    else 
    {
        result = "равна";
    }
    cout << "\r\n";
    cout << "Сумма главной диагонали (" << sumMainDiagonal << ") " << result <<" побочной (" << sumSecondaryDiagonal << ")";

    getchar();

    for (int i = 0; i < rows; ++i) 
    {
        delete[] arr[i];
    }
    delete[] arr;
}
