//2nd Question
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

//1st Question
#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int num, char frompeg, char topeg, char auxpeg)
{
    if (num == 1)
    {
        cout << " 3Move disk 1 from peg " << frompeg << " to peg " << topeg << endl;
        return;
    }
    towerOfHanoi(num - 1, frompeg, topeg, auxpeg);
    cout << " Move disk " << num << " from peg " << frompeg << " to peg " << topeg << endl;
    towerOfHanoi(num - 1, auxpeg, topeg, frompeg);
}

int main()
{
    int num;
    cin >> num;
    cout << "The sequence of moves involved in the Tower of Hanoi are :" << endl;
    towerOfHanoi(num, 'A', 'C', 'B');
    return 0;
}
