#include <iostream>

using namespace std;

int max_of_four(int a, int b, int c, int d);

int main()
{
    int a,b,c,d;

    cin >> a >> b >> c >> d;
    max_of_four(a,b,c,d);

    return 0;
}

// função que mostra o maior valor de 4 numero inteiros
int max_of_four(int a, int b, int c, int d)
{
    int max = 0;

    if(a >= b && a >= c && a >= d)
    {
        max = a;
        cout << "O maior numero eh: " << max << endl;
    }
    else if(b >= a && b >= c && b >= d)
    {
        max = b;
        cout << "O maior numero eh: " << max << endl;
    }
    else if(c >= a && c >= b && c >= d)
    {
        max = c;
        cout << "O maior numero eh: " << max << endl;
    }
    else
    {
        max = d;
        cout << "O maior numero eh: " << max << endl;
    }
    return max;
}
