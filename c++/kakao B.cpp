#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int N, K;
    cin>>N>>K;
    double list[505];
    double sum[505];
    double ret = 9876543210;
    
    for(int i = 0; i<N; i++){
        cin>>list[i];
    }
    sum[0] = 0;
    for(int i = 1; i<N+1; i++){
        sum[i] = sum[i-1]+list[i-1];
    }

    while(K<=N){
        //if (K == 1){ret = 0; break;}
        for(int i = 0; i<N-K+1 ; i++){            
            double m = (double)(sum[i+K] - sum[i])/(double)K;
            double v = 0;
            cout<<"i = "<<i << " , k = " << K <<" , sum = "<<(sum[i+K] - sum[i])<<" , m = "<<m <<"\n";
            for(int j = i; j<i+K; j++){
                v+= (list[j]-m)*(list[j]-m);
            }            
            v = v/(double)K;            
            ret = min(ret, v);
        }
        K++;
    }
    ret = sqrt(ret);
    printf("%.9lf\n", ret);
    return 0;
}
