
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

double Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	

	freopen("input.txt", "r", stdin);
    
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		int R, S, E, N = 0;
        int l, r, h = 0;
        vector<vector<int>> obs;
        
        scanf(" %d %d %d", &R, &S, &E);
        scanf(" %d", &N);
        Answer = E-S-(2*R*N);
        //printf("%d %d %d %d \n",R,S,E,N);
        
        for (int obstacles = 0; obstacles < N; obstacles++)
        {
            scanf(" %d %d %d", &l, &r, &h);
            if(h<R){
                Answer +=acos((double)(R-h)/R) *R *2;                
                Answer +=(R-R*cos(asin((double)(R-h)/R)))*2;
            }
            else{
                Answer +=M_PI*R;
                Answer +=(h-R)*2;
            }
        }
        
		printf("Case #%d\n",test_case+1);
		printf("%.10f\n", Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}