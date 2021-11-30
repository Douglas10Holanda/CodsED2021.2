#include <iostream>

using namespace std;

int main()
{
    int n = 1;
    int b = 1;
    int j = 1;

    while(n <= 100)
    {

        if(n > 50)
        {
            break;
        }
        cout << n << endl;
        n++;
    }

    cout << endl;

    while(b <= 100)
    {
        if(b % 2 != 0)
        {
            b++;
            continue;
        }
        cout << b << endl;
        b++;
    }

    cout << endl;
// loop aninhado de while
    while(j <= 10)
    {
        int i = 0;
        while(i < 3)
        {
            cout << "Numero: " << j << endl;
            i++;
        }
        j++;
    }

    return 0;
}
