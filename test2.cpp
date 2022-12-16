#include <bits/stdc++.h>
using namespace std;

int main(){
    int* a;
    cout << a << endl;
    cout << &a << endl;
    cout << "--------" << endl;
    int x = 10;
    a = &x;
    cout << a << endl;
    cout << &a << endl;
    cout << "xのメモリ" << &x << endl;
    cout << a << endl;
    cout << *a << endl;

    /*printf("%p\n", a);
    printf("%p", &a);*/
 
}