
int u[2][1000][1000];

int main() 
{
    int N = 1000, T=1000;
    int i, j, t;

#pragma scop
    for(t=1; t<=T-1; t++){
        for(i=0; i<=N-1; i++){
            for(j=0; j<=N-1; j++){
                u[t%2][i][j] = u[(t-1)%2][i==0?N-1: i-1][j] + u[(t-1)%2][i][j] + u[(t-1)%2][i==N-1?0:i+1][j]
                    + u[(t-1)%2][i==0?N-1: i-1][j==0?N-1: j-1] + u[(t-1)%2][i==N-1?0:i+1][j==N-1?0:j+1];
            }
        }
    }
#pragma endscop

    return (int) u[T-1][1];
}
