#include <iostream>

using namespace std;

int foo()
{
    return foo();
}

int main()
{
    cout << "Hello world! " << foo() << endl;
    foo();
    return 0;
}
