#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int caso = 0, a;
    scanf("%d", &a);
    while (a >= 0)
    {
        vector<int> p(14);
        p[1] = a;
        caso++;
        printf("Case %d:\n", caso);
        for (int i = 2; i < 14; i++)
        {
            scanf("%d", &p[i]);
            int n;
        }
        for (int i = 1; i < 13; i++)
        {
            int n;
            scanf("%d", &n);
            if (p[i] < n)
            {
                printf("No problem. :(\n");
                if (i != 12)
                {
                    p[i + 1] += (p[i]);
                }
            }
            else
            {
                printf("No problem! :D\n");
                if (i != 12)
                {
                    p[i + 1] += (p[i] - n);
                }
            }
        }
        scanf("%d", &a);
    }
    return 0;
}