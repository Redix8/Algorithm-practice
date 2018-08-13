#include <iostream>

main(int argc, char const *argv[])
{
    char s[101];
    while(scanf("%[^\n]\n",s) == 1){
        printf("%s\n",s);
    }

    return 0;
}
