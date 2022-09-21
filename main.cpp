#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
    string subject;
    cout<<"Enter an input string: ";
    //("0AFGHi2398-k9nm<STATIC>cvs231CVpid29300000000000000000000(PERFORCE)nmzxca3212<CODE>33211asdSASD<klocwork>mcnsbSACbc[HELOX]11111111111000vaAvm333311vmpascv<ANALYSIS>0000000000000000000vsp33311<qac>1111111111vnvnASOVAbbbbbbbbbbbbbbbbbas<2231aACV>");
    getline(cin, subject);
    smatch match1;
    smatch match2;
    string temp;
    regex r1("<[A-Z]*>");
    regex r2("[^<][A-Z]*[^>]");
    //int i = 1;
    while (regex_search(subject, match1, r1)) {
        temp = match1.str(0);
        if(regex_search(temp,match2,r2))
            cout<<match2.str(0)<<"\n";
        // suffix to find the rest of the string.
        subject = match1.suffix().str();
    }
    return 0;
}