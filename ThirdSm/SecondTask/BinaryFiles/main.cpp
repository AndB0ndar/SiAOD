#include "BinaryFile.h"
#include "TextFile.h"

using namespace std;
int main()
{
    TextFile txtfile = TextFile();
    BinaryFile bf = BinaryFile();
    vector<Phone> phones = readerSource.readSource("src.txt");
    bj.Write("bin", phones);
    vector<Phone> phones1;
    binWriter.readBin("bin", phones1);
    if (autos == phones1)
        cout << "OK";
    else
        cout << "ERROR";
}
