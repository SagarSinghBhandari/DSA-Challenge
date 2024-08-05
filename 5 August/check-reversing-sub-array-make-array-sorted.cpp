
bool checkReverse(int arr[], int n)
{
    int temp[n];
    for (int i = 0; i < n; i++){
        temp[i] = arr[i];
    }

    sort(temp, temp + n);

    int j = 0;
    for (j = 0; j < n; j++){
        if (temp[j] != arr[j])
            break;
    }

    int k;
    for (k = n - 1; k >= 0; k--){
        if (temp[k] != arr[k])
            break;
    }

    if (j >= k)
        return true;

    do{
        j++;

        if (arr[j - 1] < arr[j])
            return false;
    } while (j != k);
    
    return true;
}
