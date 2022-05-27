#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>


using std::cout, std::endl;

int n;
int ii = 1;

void printBracketsMatrixChain(int i, int j, int **brackets, char &lett) {
    if (i == j) {
        cout << lett << ii;
        ii++;
        return;
    } 
    else {
        cout << "(";
        printBracketsMatrixChain(i, brackets[i][j] - 1, brackets, lett);
        printBracketsMatrixChain(brackets[i][j], j, brackets, lett);
        cout << ")";
    }
}

void print(int **dp) {
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cout << std::left << std::setw(5) << dp[x][y];
        }
        cout << endl;
    }
    cout << endl;
}

void matrixChain(const int arr[]) 
{
    // init [dp & brackets] --------
    int **brackets = new int *[n];
    int **dp = new int *[n];

    for (int i = 0; i < n; ++i) {
        dp[i] = new int[n];
        brackets[i] = new int[n];;
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            dp[x][y] = 0;
            brackets[x][y] = 0;
        }
    }
    // -----------------------------

    for(int x = 1; x < n; x++){
        for(int i = 0; i < n - x; i++){
            int j = x + i;
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++){
                int min = dp[i][k] + dp[k + 1][j] + (arr[i] * arr[k + 1] * arr[j + 1]);
                if(min < dp[i][j]){
                    dp[i][j] = min;
                    brackets[i][j] = k + 1;
                }
            }
        }
   }
   
   print(dp);
   print(brackets);
   char lett = 'm';
   printBracketsMatrixChain(0, n - 1, brackets, lett);
   cout << endl;
}


int main() {
    int arr[] = {3, 2, 4, 2, 5};
    n = sizeof(arr) / sizeof(arr[0]) - 1;
    matrixChain(arr);
    return 0;
}
