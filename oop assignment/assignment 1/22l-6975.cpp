#include <iostream>
#include <fstream>
using namespace std;

int **allocate(int, int);
int **InputMatrix(ifstream &, int &, int &);
void OutputMatrix(int **, const int &, const int &);
int **AddMatrix(int **, int **, const int &, const int &);
int **TransposeMatrix(int **, const int &, const int &);
bool isSymmetric(int **, const int &, const int &);
void DeallocateMemory(int **, const int);
void InterchangeRows(int *&, int *&);
void InterchangeRows(int **, const int &, const int &);

int main()
{

    int r1, c1, r2, c2, r3, c3;
    ifstream f;
    f.open("hi.txt", ios::in);
    int **m1 = InputMatrix(f, r1, c1);
    int **m2 = InputMatrix(f, r2, c2);
    int **m3 = InputMatrix(f, r3, c3);

    cout << "Matrix A = " << endl;
    OutputMatrix(m1, r1, c1);
    cout << endl;

    cout << "Matrix B = " << endl;
    OutputMatrix(m2, r2, c2);
    cout << endl;

    cout << "Matrix C = " << endl;
    OutputMatrix(m3, r3, c3);
    cout << endl;

    int **m4 = AddMatrix(m1, m2, r1, c1);
    cout << "A+B = " << endl;
    OutputMatrix(m4, r1, c1);
    cout << endl;

    int **m5 = TransposeMatrix(m1, r1, c1);
    cout << "Transpose of A = " << endl;
    OutputMatrix(m5, c1, r1);
    cout << endl;

    int **m6 = TransposeMatrix(m2, r2, c2);
    cout << "Transpose of B = " << endl;
    OutputMatrix(m6, c2, r2);
    cout << endl;

    int **m7 = TransposeMatrix(m3, r3, c3);
    cout << "Transpose of C = " << endl;
    OutputMatrix(m7, c3, r3);

    cout << endl;
    bool sym = isSymmetric(m2, r2, c2);
    cout << endl;
    bool sym1 = isSymmetric(m1, r1, c1);
    cout << endl;

    InterchangeRows(m1, r1, c1);
    cout << endl;
    cout << "Matrix A after interchanging rows = " << endl;
    OutputMatrix(m1, r1, c1);
    cout << endl;

    DeallocateMemory(m1, r1);
    DeallocateMemory(m2, r2);
    DeallocateMemory(m3, r3);
    DeallocateMemory(m4, r1);
    DeallocateMemory(m5, c1);
    DeallocateMemory(m6, c2);
    DeallocateMemory(m7, c3);
    return 0;
}

int **allocate(int rows, int cols)
{
    int **arr = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
    return arr;
}

int **InputMatrix(ifstream &fin, int &rows, int &cols)
{
    fin >> rows >> cols;
    int **arr = allocate(rows, cols);

    int **row = arr;
    while (row < arr + rows)
    {
        int *col = *row;
        while (col < *row + cols)
        {
            fin >> *col;
            col++;
        }
        row++;
    }
    return arr;
}

void OutputMatrix(int **matrix, const int &rows, const int &cols)
{
    int **row = matrix;
    while (row < matrix + rows)
    {
        int *col = *row;
        while (col < *row + cols)
        {
            cout << *col << " ";
            col++;
        }
        cout << endl;
        row++;
    }
}

int **AddMatrix(int **matrixA, int **matrixB, const int &rows, const int &cols)
{

    int **r = allocate(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *(*(r + i) + j) = (*(*(matrixA + i) + j)) + (*(*(matrixB + i) + j));
        }
    }
    return r;
}

int **TransposeMatrix(int **matrix, const int &rows, const int &cols)
{
    int **arr = allocate(cols, rows);

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            *(*(arr + i) + j) = *(*(matrix + j) + i);
        }
    }
    return arr;
}

bool isSymmetric(int **mat, const int &row, const int &col)
{
    bool is_sym = true;
    int **arr = TransposeMatrix(mat, row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (*(*(arr + i) + j) != *(*(mat + i) + j))
            {
                is_sym = false;
            }
        }
    }
    if (is_sym)
    {
        cout << "matrix is symmetric" << endl;
    }
    else
    {
        cout << "matrix is not symmetric" << endl;
    }
    return is_sym;
}

void DeallocateMemory(int **matrix, const int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
        matrix[i] = 0;
    }
    delete[] matrix;
    matrix = 0;
}

void InterchangeRows(int *&row1, int *&row2)
{
    int *swap = row1;
    row1 = row2;
    row2 = swap;
}

void InterchangeRows(int **matrix, const int &rows, const int &cols)
{
    int row_1 = 1;
    int row_2 = 3;
    InterchangeRows(*(matrix + row_1 - 1), *(matrix + row_2 - 1));
}