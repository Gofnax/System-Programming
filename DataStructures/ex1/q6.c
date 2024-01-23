#include "q6.h"

double oddSuccessRec(double p, int n, int k)
{
    if(k == 1)
    {
        return calcChoose(n, 1) * pow(p, 1) * pow(1 - p, n - 1);
    }

    double res = calcChoose(n, k) * pow(p, k) * pow(1 - p, n - k);
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
