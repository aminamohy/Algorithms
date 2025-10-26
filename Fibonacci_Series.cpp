#include <iostream>
using namespace std;

int naive_Fibonacci(int n){
    if (n <= 1)
        return n;
    return naive_Fibonacci(n-1)+ naive_Fibonacci(n-2);
}
// divide and conqure
void multiply(int F[2][2], int M[2][2]) {
    int x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
    int y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
    int z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
    int w = F[1][0]*M[0][1] + F[1][1]*M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(int F[2][2], int n) {
    if (n == 0 || n == 1)
        return;

    int M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);  // F = F^2

    if (n % 2 != 0)
        multiply(F, M);
}

int fib_matrix(int n) {
    if (n == 0)
        return 0;

    int F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1);

    return F[0][0];
}
//tabulation method
int Dynamic_Fibonacci(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    int arr[n+1];
    arr[0] = 0 , arr[1] = 1 ;
    for(int i = 2 ; i <= n ; i++){
        arr[i] = arr[i-2] + arr[i-1];
    }
    return arr[n];

}
int main(){
    cout<<fib_matrix(6);
}
