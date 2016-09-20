#include <bits/stdc++.h>
using namespace std;


const int testSize = 10000000; 
int compare (const void *first, const void *second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else 
        return 0;
}
void stl(){
    vector<int> v1(testSize + 1);

    for(int i=1; i<=testSize; i++){
        v1[i] = rand();
    }
    sort(v1.begin(), v1.end());

    cout << v1[testSize / 2] << endl; 
}

void naive(){
    int* v1 = new int[testSize + 1];
    for(int i=1; i<=testSize; i++){
        v1[i] = rand();
    }

    qsort(v1, testSize + 1, sizeof(int), compare); 
    cout << v1[testSize / 2] << endl; 
    delete [] v1; 
}
int main(){
    srand((unsigned int)time(0));
    float t1, t2;
    {
        // stl test 
        clock_t c1 = clock();
        stl();
        t1 = (float)(clock() - c1) / (float)CLOCKS_PER_SEC;
    }
    {
        clock_t c1 = clock();
        naive();
        t2 = (float)(clock() - c1) / (float)CLOCKS_PER_SEC;
    }

    printf("stl = %f\nnaive = %f\nratio = %f\n", t1, t2, t1 / t2); 
    return 0;
}
