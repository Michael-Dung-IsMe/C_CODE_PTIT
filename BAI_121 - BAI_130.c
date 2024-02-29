#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//BÀI 121 - C06008: LOAI CAC TU TRUNG NHAU
int main(){
	char s1[105], res[50][50];
	int a[105] = {0};
	gets(s1);
	for(int i = 0; i < strlen(s1); ++i)
	    s1[i] = tolower(s1[i]);
	int cnt = 0, k = 1;
	char *spr = strtok(s1, " ");
	while(spr != NULL){
		strcpy(res[cnt++], spr);
		spr = strtok(NULL, " ");
	}
	for(int i = 0; i < cnt; ++i){
		if(a[i] == 0){
			for(int j = i+1; j < cnt; ++j){
				if(strcmp(res[i], res[j]) == 0)
					a[j] = 1;
			}
		}
	}
	for(int i = 0; i < cnt; ++i){
		if(a[i] == 0)
			printf("%s ", res[i]);
	}
}

//BÀI 122 - C06010: SO DEP 1
int main(){
	int t; scanf("%d", &t);
	while(t--){
		char s1[505];
		scanf("%s", s1);
		int check = 1, n = strlen(s1);
		for(int i = 0; i <= n/2; ++i){
			if((int)s1[i] != (int)s1[n-1-i] || (s1[i] - '0')%2){
				check = 0;
				break;
			}
		}
		if(check)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

//BÀI 123 - C06011: SO DEP 2
int main(){
	int T; scanf("%d", &T);
	while(T--){
		char s[505];
		scanf("%s", s);
		int sum = 0;
		int check = 0;
		int leng = strlen(s);
		for(int i = 0; i <= (leng-1)/2; i++){
			if((int)s[i] != (int)s[leng-1-i] || s[leng-1] != '8'){
				printf("NO\n");
				check = 1;
				break;
			}
			sum += (int)(s[i] - '0');
		}
		if(check == 1)
			continue;
		if(sum%10 == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

//BÀI 124 - C06012: SO DEP 3
int checkP(int n){
	if(n == 2 || n == 3) return 1;
	if(n == 1 || n%2 == 0 || n%3 == 0) return 0;
	for(int i = 5; i*i <= n; ){
		if(n%i == 0 || n%(i+2) == 0)
			return 0;
		i += 6;
	}
	return 1;
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		char s[505];
		scanf("%s", s);
		int sum = 0;
		int check = 0;
		int leng = strlen(s);
		for(int i = 0; i <= (leng-1)/2; i++){
			if((int)s[i] != (int)s[leng-1-i] || checkP(s[i] - '0') == 0){
				check = 1;
				break;
			}
		}
		if(check == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

//BÀI 125 - C06036: XAU DOI XUNG - 2
char s[100005];

int main(){
	fgets(s, sizeof(s), stdin);
	int dai = strlen(s) - 1;
	printf("%d", dai - 1);
}

//BÀI 126 - C06066: TACH DOI VA TINH TONG


//BÀI 127 - C1_1 (NOT FOUND)

//BÀI 128 - CHELLO: Hello World
int main(){
	printf("Hello PTIT.");
}

//BÀI 129 - FPT002: NHAN 3 MA TRAN GT NGUYEN
int main(){
	int m, n, p, q;
	scanf("%d%d%d%d", &m, &n, &p, &q);
	int a[m+2][n+2];
	int b[n+2][p+2];
	int c[p+2][q+2];
	int d[105][105];
	int res[105][105];
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j)
			scanf("%d",&a[i][j]);			
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < p; ++j)
			scanf("%d",&b[i][j]);			
	}
	for(int i = 0; i < p; ++i){
		for(int j = 0; j < q; ++j)
			scanf("%d",&c[i][j]);			
	}
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < p; ++j){
			int sum = 0;
			for(int k = 0; k < n; ++k)
				sum += a[i][k] * b[k][j];
			d[i][j] = sum;
		}
		for(int j = 0; j < q; ++j){
			int sum = 0;
			for(int k = 0; k < p; ++k)
				sum += d[i][k] * c[k][j];
			res[i][j] = sum;
		}
	}
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < q; ++j)
			printf("%d ", res[i][j]);
		printf("\n");
	}
}

//BÀI 130 - FTP001: TAO MA TRAN DON GIAN
int main(){
	int n; scanf("%d", &n);
	int a[n+3][n+3];
	for(int i = 0; i < n; ++i){
		int j = 0;
		while(j <= i){
			printf("0 ");
			++j;
		}
		j = 1;
		while(j < n-i){
			if(j == n-i-1)
				printf("%d", j++);
			else
				printf("%d ", j++);
		}
		printf("\n");
	}
}


//END
