#include <iostream>
using namespace std;

class CTestData
{
public:
    CTestData() { cout << "CTestData()" << endl; }
    ~CTestData() { cout << "~CTestData()" << endl; }

    CTestData(int nParam) : m_nData(nParam)
    {
        cout << "CTestData(int)" << endl;
    }

    int GetData(void) const { return m_nData; }
    void SetData(int nParam) { m_nData=nParam; }

private:
    int m_nData=0;

};

int TestFunc(const CTestData &param)
{
    cout << "TestFunc> a: " << param.GetData() << endl;
}


int main()
{
    cout << "*** Begin ***" << endl;
    // CTestData a(10);
    TestFunc(5);

    // cout << "a: " << a.GetData() << endl;

    return 0;
}
