#include <stdio.h>
#include <math.h>
#include <string.h>
#define ll long long

//BÀI 181 - C05010: TONG CAC SNT THUOC TAM GIAC TREN
int checkP(int n){
	if(n == 2 || n == 3) return 1;
	if(n == 1 || n%2 == 0 || n%3 == 0) return 0;
	for(int i = 5; i*i <= n; ++i){
		if(n%i == 0 || n%(i+2) == 0)
			return 0;
		i += 6;
	}
	return 1;
}

int main(){
	int n, sum = 0;
	scanf("%d", &n);
	int a[n+2][n+2];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
	}
	for(int i = 0; i < n; ++i){
		for(int j = i; j < n; ++j){
			if(checkP(a[i][j]))
				sum += a[i][j];
		}
	}
	printf("%d", sum);
}

//BÀI 182 - C05011: TICH MA TRAN VOI CHUYEN VI CUA NO
int main(){
	int t; scanf("%d", &t);
	int k = 0;
	while(t--){
		int m, n;
		scanf("%d%d", &m, &n);
		int a[m+2][n+2];
		int b[n+2][m+2];
		int res[105][105];
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				scanf("%d",&a[i][j]);
				b[j][i] = a[i][j];
			}
		}
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < m; ++j){
				int sum = 0;
				for(int k = 0; k < n; ++k)
					sum += a[i][k] * b[k][j];
				res[i][j] = sum;
			}
		}
		printf("Test %d:\n", ++k);
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < m; ++j)
				printf("%d ", res[i][j]);
			printf("\n");
		}
	}
}

//BÀI 183 - C05012: TICH MA TRAN CHEO
int main(){
	int t; scanf("%d", &t);
	int k = 0;
	while(t--){
		int m, n;
		scanf("%d", &n);
		int a[n+2][n+2];
		int b[n+2][n+2];
		int res[105][105];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(j <= i)
					a[i][j] = j+1;
				else
					a[i][j] = 0;
				b[j][i] = a[i][j];
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				int sum = 0;
				for(int k = 0; k < n; ++k)
					sum += a[i][k] * b[k][j];
				res[i][j] = sum;
			}
		}
		printf("Test %d:\n", ++k);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j)
				printf("%d ", res[i][j]);
			printf("\n");
		}
	}
}

//BÀI 184 - C05016: MA TRAN XOAN OC 1
int main(){
	int n; scanf("%d", &n);
	int a[n+2][n+2];
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
		if(hang_1 != hang_2+1){
			for(int i = cot_2; i >= cot_1; i--){
				a[hang_2][i] = cnt++;
			}
		}
		hang_2--;
		if(cot_1 != cot_2+1){
			for(int i = hang_2; i >= hang_1; i--){
				a[i][cot_1] = cnt++;
			}
		}
		cot_1++;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

//BÀI 185 - C05018: MA TRAN XOAN OC NGUOC
int main(){
	int t; scanf("%d", &t);
	int k = 1;
	while(t--){
		int n;
		scanf("%d", &n);
		int a[n+2][n+2];
		int cnt = n*n;
		int hang_1 = 0, hang_2 = n-1;
		int cot_1 = 0, cot_2 = n-1;
		while(cnt){
			for(int i = cot_1; i <= cot_2; i++){
				a[hang_1][i] = cnt--;
			}
			hang_1++;
			for(int i = hang_1; i <= hang_2; i++){
				a[i][cot_2] = cnt--;
			}
			cot_2--;
			if(hang_1 != hang_2+1){
				for(int i = cot_2; i >= cot_1; i--){
					a[hang_2][i] = cnt--;
				}
			}
			hang_2--;
			if(cot_1 != cot_2+1){
				for(int i = hang_2; i >= hang_1; i--){
					a[i][cot_1] = cnt--;
				}
			}
			cot_1++;
		}
		printf("Test %d:\n", k);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j)
				printf("%d ", a[i][j]);
			printf("\n");
		}
		++k;
	}
}

//BÀI 186 - C05019: MA TRAN XOAN OC NGUYEN TO
int a[105][105];
int prime[10005];

int checkP(long long n){
	if(n == 2 || n == 3) return 1;
	if(n == 1 || n%2 == 0 || n%3 == 0) return 0;
	for(long long i = 5; i*i <= n; ){
		if(n%i == 0 || n%(i+2) == 0)
			return 0;
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

//BÀI 187 - C05020: MA TRAN XOAN OC FIBONACCI
long long fibo(int n){
	if(n == 0 || n == 1)
		return n;
	else
		return fibo(n-1) + fibo(n-2);
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n+2][n+2];
	int hang_1 = 0, hang_2 = n-1;
	int cot_1 = 0, cot_2 = n-1;
	int cnt = 0;
	while(hang_1 <= hang_2 && cot_1 <= cot_2){
		for(int i = cot_1; i <= cot_2; i++){
			a[hang_1][i] = fibo(cnt++);
		}
		hang_1++;
		for(int i = hang_1; i <= hang_2; i++){
			a[i][cot_2] = fibo(cnt++);
		}
		cot_2--;
		if(hang_1 != hang_2+1){
			for(int i = cot_2; i >= cot_1; i--){
				a[hang_2][i] = fibo(cnt++);
			}
		}
		hang_2--;
		if(cot_1 != cot_2+1){
			for(int i = hang_2; i >= hang_1; i--){
				a[i][cot_1] = fibo(cnt++);
			}
		}
		cot_1++;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

//BÀI 188 - C05026: TIM HANG NHIEU SO NGUYEN TO NHAT
int checkP(int n){
	if(n == 2 || n == 3) return 1;
	if(n == 1 || n%2 == 0 || n%3 == 0) return 0;
	for(int i = 5; i*i <= n; ++i){
		if(n%i == 0 || n%(i+2) == 0)
			return 0;
		i += 6;
	}
	return 1;
}

int main(){
	int n, sum = 0, check = 0;
	scanf("%d", &n);
	int a[n+2][n+2];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
	}
	for(int i = 0; i < n; ++i){
		int cnt = 0;
		for(int j = 0; j < n; ++j){
			if(checkP(a[i][j]))
				cnt++; 
		}
		if(cnt > sum){
			sum = cnt;
			check = i+1;
		}
		cnt = 0;
	}
	printf("%d\n", check);
	for(int i = 0; i < n; ++i){
		if(checkP(a[check-1][i]))
			printf("%d ", a[check-1][i]);
	}
}

//BÀI 189 - C05027: SO LON NHAT TRONG BANG
int main(){
	int n; scanf("%d",  &n);
	int hang = 1000005;
	int cot = 1000005;
	while(n--){
		int x, y;	//Tim x, y min vi tai cac hang va cot do se duoc tang nhieu lan nhat --> so gt max trong bang
		scanf("%d%d", &x, &y);
		if(x < hang)
			hang = x;
		if(y < cot)
			cot = y;
	}
	printf("%lld", (ll)hang * cot);
} 

//BÀI 190 - C06005: DEM SO LAN XUAT HIEN CAC TU TRONG XAU
int main(){
	char s1[105], res[50][50];
	gets(s1);
	for(int i = 0; i < strlen(s1); ++i)
	    s1[i] = tolower(s1[i]);
	int cnt = 0, k = 1;
	char *spr = strtok(s1, " ");
	while(spr != NULL){
		strcpy(res[cnt++], spr);
		spr = strtok(NULL, " ");
	}
	int b[105] = {0};
	for(int i = 0; i < cnt; ++i){
		if(b[i] == 0){
			for(int j = i+1; j < cnt; ++j){
				if(strcmp(res[i], res[j]) == 0){
					b[j] = 1;
					k++;
				}
			}
			printf("%s %d\n", res[i], k);
			k = 1;
		}
	}
}

//END
