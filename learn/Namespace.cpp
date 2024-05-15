#include <stdio.h>

//  :: = operateur de resolution de portee

int g_var = 4;
int function(void){return 4;};


namespace foo
{
    int g_var = 50;
    int function(void){return 50;};
}

namespace bar
{
    int g_var = 666;
    int function(void){return 6666;};
}

namespace muf = bar;

int main()
{
    printf("var = %d\n", g_var);
    printf("function = %d\n\n", function());
    printf("foo var = %d\n", foo::g_var);
    printf("muf gvar = %d", muf::g_var);
    return 0;
}