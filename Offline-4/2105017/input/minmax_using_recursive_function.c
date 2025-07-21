int arr[6];

int find_min(int n)
{
    if (n == 1)
        return arr[0];
    int min_rest = find_min(n - 1);
    if (arr[n - 1] < min_rest)
        return arr[n - 1];
    else
        return min_rest;
}

int find_max(int n)
{
    if (n == 1)
        return arr[0];
    int max_rest = find_max(n - 1);
    if (arr[n - 1] > max_rest)
        return arr[n - 1];
    else
        return max_rest;
}

int main()
{
    arr[0] = 5;
    arr[1] = 2;
    arr[2] = 8;
    arr[3] = 1;
    arr[4] = 9;
    arr[5] = 3;
    int n = 6;

    int min = find_min(n);
    int max = find_max(n);

    println(min);
    println(max);

    return 0;
}
