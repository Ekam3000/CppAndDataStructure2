// move all disks from A to C
// pick 1 disk at time
// can't place a big on small disk

// shift n-1 disks from A to B
// shift nth disk from A to C
// shift n-1 disks from B to C
#include <iostream>
using namespace std;
void move(int n, char src, char helper, char dest)
{
    if (n == 0)
    {
        return;
    }
    // rec case
    // move n-1 disk from from src to helper
    move(n - 1, src, dest, helper);
    cout << "shift disk " << n << " from " << src << " to " << dest << endl; // the nth disk
    move(n - 1, helper, src, dest);
}
int main()
{
    int n;
    cin >> n;
    move(n, 'A', 'B', 'C');
    return 0;
}