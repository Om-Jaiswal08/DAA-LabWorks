#include <iostream>
using namespace std;
const int MAX = 100;

void lcs(char X[], char Y[], int m, int n, int cost[MAX][MAX], char dir[MAX][MAX])
{
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cost[i][j] = 0;
            dir[i][j] = ' ';
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1] && i != j)  
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

    cout << "Longest Repeating Subsequence: " << lcs << endl;
}

void printCostTable(char Y[], int n, int cost[MAX][MAX], char X[], int m) {
    cout << "\nCost Table :" << endl;
    cout << "    ";

    for (int j = 0; j <= n; j++) {
        if (j == 0)
            cout << "  ";
        else
            cout << Y[j - 1] << " ";
    }
    cout << endl;

    for (int i = 0; i <= m; i++) {
        if (i == 0)
            cout << "  ";
        else
            cout << X[i - 1] << " ";

        for (int j = 0; j <= n; j++) {
            if (cost[i][j] < 10)
                cout << " ";
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
}

void printDirTable(char Y[], int n, char dir[MAX][MAX], char X[], int m) {
    cout << "\nDirection Table:" << endl;
    cout << "    ";

    for (int j = 0; j <= n; j++) {
        if (j == 0)
            cout << "  ";
        else
            cout << Y[j - 1] << " ";
    }
    cout << endl;

    for (int i = 0; i <= m; i++) {
        if (i == 0)
            cout << "  ";
        else
            cout << X[i - 1] << " ";

        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                cout << "  ";
            else
                cout << dir[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    char S[] = {'A','A','B','C','B','D','C'};
    int m = sizeof(S) / sizeof(S[0]);

    int cost[MAX][MAX];
    char dir[MAX][MAX];

    lcs(S, S, m, m, cost, dir);

    cout << "Length of Longest Repeating Subsequence: " << cost[m][m] << endl;
    printLCS(S, m, m, dir);

    printCostTable(S, m, cost, S, m);
    printDirTable(S, m, dir, S, m);

    return 0;
}

