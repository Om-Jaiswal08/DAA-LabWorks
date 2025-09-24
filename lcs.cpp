#include <iostream>
using namespace std;
const int MAX = 100;

void lcs(char X[], char Y[], int m, int n, int cost[MAX][MAX], char dir[MAX][MAX])
{
    for (int i = 0; i <= m; i++)
        cost[i][0] = 0;
    for (int j = 0; j <= n; j++)
        cost[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                cost[i][j] = cost[i - 1][j - 1] + 1;
                dir[i][j] = 'D'; 
            }
            else if (cost[i - 1][j] >= cost[i][j - 1])
            {
                cost[i][j] = cost[i - 1][j];
                dir[i][j] = 'U';
            }
            else
            {
                cost[i][j] = cost[i][j - 1];
                dir[i][j] = 'L'; 
            }
        }
    }
}

void printLCS(char X[], int m, int n, char dir[MAX][MAX])
{
    string lcs = "";
    int i = m, j = n;

    while (i > 0 && j > 0)
    {
        if (dir[i][j] == 'D')
        {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        }
        else if (dir[i][j] == 'U')
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    cout << "LCS: " << lcs << endl;
}

int main()
{
    char X[] = {'A','G','C','C','C','T','A','A','G','G','G','C','T','A','C','C','T','A','G','C','T','T'};
    char Y[] = {'G','A','C','A','G','C','C','T','A','C','A','A','G','C','G','T','T','A','G','C','T','T','G'};
    int m = sizeof(X) / sizeof(X[0]);
    int n = sizeof(Y) / sizeof(Y[0]);
    int cost[MAX][MAX];
    char dir[MAX][MAX];
    lcs(X, Y, m, n, cost, dir);
    cout << "Length of LCS: " << cost[m][n] << endl;
    printLCS(X, m, n, dir);
    for(int i = 0 ; i<= m+1 ; i++)
    {
        for(int j = 0 ; j<= n+1;j++)
        {
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

