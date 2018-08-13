#include <iostream>

main(int argc, char const *argv[])
{
    char c;
    while((c=getchar()) && c!=EOF){
        printf("%c",c);
    }
    return 0;
}
