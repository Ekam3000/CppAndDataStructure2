#define MOD 10e7
\long countArray(int n, int k , int x)
{
    // return the number of ways to fill in the array
    lomg oneCount =1;
    long nonOneCount =0;
    for(int i=1; i<n; i++)
    {
        long prevOneCount = oneCount;
        oneCount = (nonOneCount*(k-1))%MOD;
        nonOneCount = (prevOneCount +((nonOneCount)*(k-2))%MOD)%MOD;

    }
    if(x==1)
    {
        return oneCount;
    }
    else
    {
        return nonOneCount;
    }
}