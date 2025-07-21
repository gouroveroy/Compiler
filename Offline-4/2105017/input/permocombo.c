int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int permutation(int n, int r)
{
    return factorial(n) / factorial(n - r);
}

int combination(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main()
{
    int n = 5;
    int r = 3;
    int perm = permutation(n, r);
    int comb = combination(n, r);
    println(perm);
    println(comb);
    return 0;
}