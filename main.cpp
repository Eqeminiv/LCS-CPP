#include <iostream>
#include <stack>

using namespace std;



int main()
{
    string a,b;
    cout << "Podaj pierwszy ciag: ";
    cin >> a;
    cout << endl << "Podaj drugi ciag: ";
    cin >> b;

    stack<char> r;

    int d[a.length()+1][b.length()+1];

    //wyliczanie dlugosci LCS
    for(int n = 0; n <= a.length(); n++)
    {
        for(int k=0; k <= b.length(); k++)
        {
            if (n == 0 || k == 0)
                d[n][k] = 0;
            else if (a[n-1] == b[k-1])
                d[n][k] = d[n-1][k-1]+1;
            else
                d[n][k] = max(d[n][k-1], d[n-1][k]);
        }
    }
    int n = a.length(), k = b.length();
    //cout << n << endl << k << endl;

    //przechodzenie na ukos
    while(n >= 0 && k >= 0)
    {
        if(a[n-1]==b[k-1])
        {
            r.push(a[n-1]);
            n--;
            k--;
        }
        else if(d[n][k] == d[n][k-1])
            k--;
        else
            n--;
    }

    //zdejmowanie ze stosu
    while(!r.empty())
    {
        cout << r.top();
        r.pop();
    }
   // cout << endl << d[a.length()][b.length()];




    //cout << endl << d[a.length()][b.length()];


    //cout << endl << a.length();
    return 0;
}
