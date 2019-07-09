/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int Answer;
int mem[1000001];
int sum[1000001];
int precal(int num){
    if(num==1) return mem[num];    
    if(mem[num]){
        return mem[num];
    }
    if(num%2==1){
        mem[num]=precal(num+1)+1;
    }
    if(num%2==0){
        mem[num]=precal(num/2)+1;
    }
    return mem[num];
}





int main(int argc, char** argv)
{
	int T, test_case;
	memset(mem,0,sizeof(mem));
    memset(sum,0,sizeof(sum));

    mem[0] = 0;
    mem[1] = 0;
    mem[2] = 1;
    for (int i = 3; i < 1000001; i++)
    {
        if(i%2==1){
            mem[i]+=1;
        }
        else if(i%2==0){
            mem[i]=mem[i/2]+1;
            mem[i-1] +=mem[i];
        }
    }
    for (int i = 2; i < 1000001; i++)
    {
        sum[i] = sum[i-1]+mem[i];
    }
    

	//freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		int a, b = 0;
        scanf("%d %d",&a, &b);
        //cin>>a >> b;
        Answer = sum[b]-sum[a-1];      
        
        printf("Case #%d\n",test_case+1);
        printf("%d\n",Answer);
		// Print the answer to standard output(screen).
		//cout << "Case #" << test_case+1 << endl;
		//cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}