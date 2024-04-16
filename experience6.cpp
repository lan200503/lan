#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Square_matrix
{
    public:
        Square_matrix(){};
        Square_matrix(int n);
        ~Square_matrix()
        {
            delete[] data;
        }

        Square_matrix& IntMatrix(int n);
        void printMatrix() const;
        friend ostream& operator <<(ostream& stream,Square_matrix& square_matrix);
        friend istream& operator >>(istream& stream,Square_matrix& square_matrix);
        Square_matrix& operator+(Square_matrix&other)
        {
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    data[i*size+j]+=other.data[i*size+j];
                }
            }

            return *this;
        }
        void operator=(Square_matrix&other)
        {
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    data[i*size+j] = other.data[i*size+j];
                }
            }
        }

    private:
        int size;
        int* data;
        


};

Square_matrix::Square_matrix(int n)
:size(n)
{
    data = new int [n*n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            data[i*size+j] = 1;
        }
    }
}

Square_matrix& Square_matrix:: IntMatrix(int n)
{
    data = new int [n*n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            data[i*n+j] = 0;
        }
    }

    return *this;
}

void Square_matrix::printMatrix() const
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << data[i * size + j]<<" ";
        }
            cout << endl;
    }
}

ostream& operator <<(ostream& stream,Square_matrix& square_matrix)
{
    for(int i=0;i<square_matrix.size;i++)
    {
        for(int j=0;j<square_matrix.size;j++)
        {
            stream <<square_matrix.data[i*square_matrix.size+j] <<" ";
        }
        stream << endl;
    }
    return stream;
}


istream& operator >>(istream& stream,Square_matrix& square_matrix)
{
    for(int i=0;i<square_matrix.size;i++)
    {
        for(int j=0;j<square_matrix.size;j++)
        {
            stream >> square_matrix.data[i*square_matrix.size+j];
        }
    }
    return stream;
}


int main()
{
    Square_matrix matrix1(5);
    Square_matrix matrix2(5);


    cin >> matrix1 >> matrix2;

    matrix1 = (matrix1 + matrix2.IntMatrix(5));

    
    cout << endl <<matrix1 << endl << matrix2;

    matrix1.~Square_matrix();
    matrix2.~Square_matrix();


}