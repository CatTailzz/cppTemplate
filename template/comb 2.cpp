long long C(int n, int m)
{
    if (m == 0 || m == n)
    {
        return 1;
    }
    return C(n - 1, m - 1) + C(n - 1, m);
}