int arr[6];

int find_min(int n)
{
    int min = arr[0], i;
    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int find_max(int n)
{
    int max = arr[0], i;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
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