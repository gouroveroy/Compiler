int main()
{
    int arr[6];
    arr[0] = 5;
    arr[1] = 2;
    arr[2] = 8;
    arr[3] = 1;
    arr[4] = 9;
    arr[5] = 3;
    int n = 6, i;
    int min = arr[0];
    int max = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    println(min);
    println(max);

    return 0;
}