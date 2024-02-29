#include <stdio.h>
#include <math.h>

//BÀI 91: HIGHEST SUM SUBARRAY
long long A[100005];

long long maxSum(long long A[], int n){
    long long max_check = A[0];
    long long max_final = A[0];
    for (int i = 1; i < n; i++){
        max_check = ((A[i] > (max_check + A[i])) ? A[i] : (max_check + A[i]));
        max_final = ((max_final > max_check) ? max_final : max_check);
    }
    return max_final;
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
	    int n;
	    scanf("%d", &n);
	    for (int i = 0; i < n; i++) {
	        scanf("%lld", &A[i]);
	    }
	    long long res = maxSum(A,n);
	    printf("%lld\n", res);
	}
	return 0;
} 

//BÀI 93: SWAPPING ROWS IN A MATRIX
int main(){
		int row,col, a, b;
    scanf("%d %d", &row,&col);
    int A[row][col];
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
            scanf("%d", &A[i][j]);
	}
	scanf("%d %d", &a, &b);
    a--;
	b--;
    for(int i = 0; i < col; i++){
    	int temp = A[a][i];
    	A[a][i] = A[b][i];
    	A[b][i] = temp;
	}
	for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d ", A[i][j]);
    	}
        printf("\n");
    }
    return 0;
}

//BÀI 94: PRIME SPIRAL MATRIX
int a[105][105];
int prime[10005];

int checkP(long long n){
	if(n == 2 || n == 3)
		return 1;
	if(n == 1 || n%2 == 0 || n%3 == 0)
		return 0;
	for(long long i = 5; i*i <= n; ){
		if(n%i == 0 || n%(i+2) == 0)	return 0;
			i += 6;
	}
	return 1;
}

int main(){
	int dem = 0;
	for(int i = 2; i <= 10005; i++){
		if(checkP(i)){
			prime[dem] = i;
			++dem;
		}
	}
	int T; scanf("%d",&T);
	for(int k = 1; k <= T; k++){
		int n;
		scanf("%d", &n);
		int cnt = 1;
		int hang_1 = 0, hang_2 = n-1;
		int cot_1 = 0, cot_2 = n-1;
		while(cnt <= n*n){
			for(int i = cot_1; i <= cot_2; i++){
				a[hang_1][i] = cnt++;
			}
			hang_1++;
			for(int i = hang_1; i <= hang_2; i++){
				a[i][cot_2] = cnt++;
			}
			cot_2--;
			for(int i = cot_2; i >= cot_1; i--){
				a[hang_2][i] = cnt++;
			}
			hang_2--;
			for(int i = hang_2; i >= hang_1; i--){
				a[i][cot_1] = cnt++;
			}
			cot_1++;
		}
		printf("Test %d:\n", k);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int count = a[i][j] - 1;
				printf("%d ", prime[count]);
			}
			printf("\n");
		}
	}
}

//BÀI 97: PTIT EMAIL ADDRESS
void inlower(char c[]){
	for(int i = 0; i < strlen(c); i++)
		c[i] = tolower(c[i]);
}

int main(){
	char c1[1000];
	char res[20][50];
	char ptit[1005];
	gets(c1);
	inlower(c1);
	int cnt = 0;
	char *spr = strtok(c1, " ");
	while(spr != NULL){
		strcpy(res[cnt++], spr);
		spr = strtok(NULL, " ");
	}
	for(int i = 0; i < cnt-1; i++){
		printf("%c", res[i][0]);
	}
	printf("%s", res[cnt-1]);
	printf("@ptit.edu.vn");
}

//BÀI 98: DIFFERENCE OF TWO BIG INTEGERS
int main(){
	int t; scanf("%d", &t);
	getchar();
	while(t--){
		char s1[1003], s2[1003];
		gets(s1); gets(s2);
		int n1 = strlen(s1), n2 = strlen(s2);
		int dai = fmax(n1,n2);
		int u[1003] = {0}, v[1003] = {0}, res[1005] = {0};
		for(int i = 0; i < n1; ++i)
			u[i] = s1[n1-1-i] - '0';
		for(int i = 0; i < n2; ++i)
			v[i] = s2[n2-1-i] - '0';
		int check = 0;
		if(n1 == n2){
			for(int i = n1-1; i >= 0; --i){
				if(u[i] - v[i] < 0){
					check = 1;
					break;
				}
			}
		}
		if(check){
			int cnt = 0;
			for(int i = 0; i < dai-1; ++i){
				res[i] = v[i] - u[i] - cnt;
				if(res[i] < 0){
					res[i] += 10;
					cnt = 1;
				}
			}
			res[dai-1] = v[dai-1] - u[dai-1] - cnt;
			if(res[dai-1] != 0)
				printf("%d", abs(res[dai-1]));
		}
		else{
			int cnt = 0;
			for(int i = 0; i < dai-1; ++i){
				res[i] = u[i] - v[i] - cnt;
				if(res[i] < 0){
					res[i] += 10;
					cnt = 1;
				}
			}
			res[dai-1] = u[dai-1] - v[dai-1] - cnt;
			if(res[dai-1] != 0)
				printf("%d", abs(res[dai-1]));
		}
		for(int i = dai-2; i >= 0; --i)
			printf("%d", res[i]);
		printf("\n");
	}
}
