#include <iostream>

using namespace std;

int CompareData(const void *pLeft, const void *pRight)
{
    cout << *(int *)pLeft << "  " << *(int *)pRight << endl;
    return *(int *)pLeft - *(int *)pRight;
}


int main()
{
    int aList[5]={30, 50, 10, 20, 40};

    qsort(aList, 5, sizeof(int), CompareData);

    for(auto &n : aList) cout << n << '\t';
    cout << endl;
    
    return 0;
}