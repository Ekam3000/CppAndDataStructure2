#define MOD 100000007
int substring(string s)
{
    long long totalSum = s[0] -'0';
    long long lastValue = s[0] -'0';

    for(int i=1;i<s.length();i++)
    {
        lastValue = lastValue*10 +(s[i]-'0')*(i+1);
        lastValue=lastValue%MOD;
        totalSum = (totalSum + lastValue)%MOD;
    }
    retiurn totalSum;
}