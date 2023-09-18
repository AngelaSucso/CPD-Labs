#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
#define MAX 1000

vector<vector<double>> crearMatriz(int fil, int col)
{
    vector<double> vectorcito(col, 0);
    vector<vector<double>> matriz;

    for(int i = 0; i < fil; i++){
        matriz.push_back(vectorcito);
    }

    return matriz;
}

void asignarCeros(vector<double> &vec)
{
    for(int i = 0; i < vec.size(); i++){
        vec[i] = 0;
    }
}

int main()
{
    cout << "MAX" << "\t" <<"for1"<< "\t" <<"for2" << endl;

    /* Initialize A and x, assign y = 0 */
    vector<vector<double>> A = crearMatriz(MAX, MAX);
    vector<double> x(MAX, 0), y(MAX, 0);

    /* First pair of loops */
    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            y[i] += A[i][j]*x[j];
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    cout << MAX << "\t"<< chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() << "\t";

    /* Assign y = 0 */
    asignarCeros(y);

    /* Second pair of loops */
    start_time = std::chrono::high_resolution_clock::now();

    for (int j = 0; j < MAX; j++){
        for (int i = 0; i < MAX; i++){
            y[i] += A[i][j]*x[j];
        }
    }

    end_time = std::chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() << endl;
}
