#include "q6.h"

double oddSuccessRec(double p, int n, int k)
{
    if(k == 1)
    {
        return calcChoose(n, 1) * power(p, 1) * power(1 - p, n - 1);
    }

    double res = calcChoose(n, k) * power(p, k) * power(1 - p, n - k);
    return res + oddSuccessRec(p, n, k - 2);
}

double calcChoose(int n, int k)
{
    double res = 0;
    int nFact = 1, kFact = 1, nkFact = 1;

    for(int i = 1; i <= n; i++)
        nFact *= i;
    for(int i = 1; i <= k; i++)
        kFact *= i;
    for(int i = 1; i <= n - k; i++)
        nkFact *= i;
    
    res = (double)(nFact / (kFact * nkFact));
    return res;
}

double power(double base, int exp)
{
    double res = base;
    for(int i = 2; i <= exp; i++)
        res *= base;
    return res;
}