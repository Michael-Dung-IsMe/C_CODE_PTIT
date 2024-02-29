#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//CTest001: TIM SO LON NHAT
int main(){
	long long max = -1e18;
	long long n;
	while(scanf("%lld", &n) != EOF){
		if(n > max)
			max = n;
	}
	printf("%lld", max);
	return 0;
}

//CTest002: TIM TU DAI NHAT


//CTest003: LON NHAT - NHO NHAT
int main(){
	long long max = -1e18;
	long long min = 1e18;
	long long n;
	while(scanf("%lld", &n) != EOF){
		if(n < min)
			min = n;
		if(n > max)
			max = n;
	}
	printf("%lld %lld", max, min);
	return 0;
}

//CTest007: HE CO SO 3
int main(){
	int t; scanf("%d", &t);
	getchar();
	while(t--){
		char s1[22];
		gets(s1);
		int check = 1;
		for(int i = 0; i < strlen(s1); ++i){
			if(s1[i]-'0' != 0 && s1[i]-'0' != 1 && s1[i]-'0' != 2){
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

//CTest010: MA HOA
int main(){
	int t; scanf("%d", &t);
	while(t--){
		char s1[105], s2[105];
		scanf("\n");
		gets(s1);
		strcpy(s2, s1);
		for(int i = 0; i < strlen(s2); ++i){
			int check = 0, cnt = 0;
			for(int j = 0; j < strlen(s1); ++j)
				if(s2[i] == s1[j])
					cnt++;
			for(int j = i-1; j >= 0; --j)
				if(s2[i] == s1[j])
					check = 1;	
			if(!(check))
				printf("%c%d", s1[i], cnt);
		}
		printf("\n");
	}
}

//CTest019: SAP XEP COT TRONG MA TRAN
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		int a[n+3][m+3];
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j)
				scanf("%d", &a[i][j]);
		}
		for(int i = 1; i <= n; ++i){
			for(int j = i; j <= n; ++j){
				if(a[i][k] > a[j][k]){
					int tmp = a[i][k];
					a[i][k] = a[j][k];
					a[j][k] = tmp;
				}
			}
		}
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j)
				printf("%d ", a[i][j]);
			printf("\n");
		}
	}
}

//CTest039: SAP XEP CHU SO
int main(){
	int t; scanf("%d", &t);
	while(t--){
		long long n; scanf("%lld", &n);
		int a[20] = {0};
		while(n){
			int k = n%10;
			a[k]++;
			n /= 10;
		}
		for(int i = 1; i <= 9; ++i){
			while(a[i] > 0){
				printf("%d", i);
				a[i]--;
			}
		}
		printf("\n");
	}
}
