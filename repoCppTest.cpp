#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdint>
#include <climits>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main(int argc, char const *argv[])
{
/*[[[cog
import cog
fnames = ['DoSomething', 'DoAnotherThing', 'DoLastThing']
for fn in fnames:
    cog.outl("void %s();" % fn)
]]]*/
void DoSomething();
void DoAnotherThing();
void DoLastThing();
//[[[end]]]
    printf("nice");
    return 0;
}