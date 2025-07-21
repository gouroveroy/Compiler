int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    return (a / gcd(a, b)) * b;
}

int main()
{
    int a = 12, b = 15;
    int resultGCD = gcd(a, b);
    int resultLCM = lcm(a, b);
    println(resultGCD);
    println(resultLCM);
    return 0;
}