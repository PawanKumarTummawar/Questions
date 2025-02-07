Implement Pow

    double
    power(double b, int e)
{
    if (e == 0)
        return 1;
    if (e < 0)
        return 1 / power(b, -e);

    double tempans = power(b, e / 2);
    if (e % 2 == 0)
    {
        return tempans * tempans;
    }
    else
    {
        return b * tempans * tempans;
    }