#include <stdio.h>
#include <math.h>
#include <string.h>

//BÀI 91 - C04002: SO NGUYEN TO TRONG DAY
int checkP(int n){
	if(n == 2 || n == 3) return 1;
	if(n == 1 || n%2 == 0 || n%3 == 0) return 0;
	for(int i = 5; i*i <= n; ){
		if((n%i == 0 || n%(i+2) == 0))
			return 0;
		i += 6;
	}
	return 1;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int a[n];
		for(int i = 0; i < n; ++i){
			scanf("%d", a+i);
			if(checkP(a[i]))
				printf("%d ", a[i]);
		}
		printf("\n");
	}
}

//BÀI 92 - C04003: MANG DOI XUNG
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int a[n], check = 1;
		for(int i = 0; i < n; ++i)
			scanf("%d", a+i);
		for(int i = 0; i < n; ++i){
			if(a[i] != a[n-1-i]){
				check  = 0;
				break;
			}		
		}
		if(check)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

//BÀI 93 - C04004: SO FIBONACCI
long long fibo(long long n){
	long long fib[95];
	fib[1] = 1;
	fib[2] = 1;
	for(int i = 3; i <= 92; ++i){
		fib[i] = fib[i-1] + fib[i-2];
		if(i == n)
			break;
	}
	return fib[n];
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		long long n; scanf("%lld", &n);
		printf("%lld\n", fibo(n));
	}
}

//BÀI 94 - C04005: SO LON NHAT
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int a[n], max = -1e9;
		for(int i = 0; i < n; ++i){
			scanf("%d", a+i);
		if(a[i] > max)
			max = a[i];
		}
		printf("%d\n", max);
		for(int i = 0; i < n; ++i){
			if(max == a[i])
				printf("%d ", i);
		}
		printf("\n");
	}
}

//BÀI 95 - C04006: DAO NGUOC MANG SO
int main(){
	int n; scanf("%d", &n);
	int a[n+2];
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);
	for(int i = n-1; i >= 0; --i)
		printf("%d ", a[i]);
}

//BÀI 96 - C04007: CHEN MANG 1
int main(){
	int n, m, k; scanf("%d%d", &n, &m);
	int a[n+3], b[m+3], c[n+m+3];
	for(int i = 1; i <= n; ++i)
		scanf("%d", a+i);
	for(int i = 1; i <= m; ++i)
		scanf("%d", b+i);
	scanf("%d", &k);
	for(int i = 1; i <= k; ++i)
		c[i] = a[i];
	for(int i = 1; i <= m; ++i)
		c[k+i] = b[i];
	for(int i = k+1; i <= n; ++i)
		c[m+i] = a[i];
	for(int i = 1; i <= n+m; ++i)
		printf("%d ", c[i]);
}

//BÀI 97 - C04008: CHEN MANG 2
int main(){
	int t; scanf("%d", &t);
	int cnt = 1;
	while(t--){
		int n, m, k; scanf("%d%d%d", &n, &m, &k);
		int a[n+3], b[m+3];
		for(int i = 1; i <= n; ++i)
			scanf("%d", a+i);
		for(int i = 1; i <= m; ++i)
			scanf("%d", b+i);
		printf("Test %d:\n", cnt++);
		for(int i = 1; i <= n; ++i){
			printf("%d ", a[i]);
			if(i == k){
				for(int j = 1; j <= m; ++j)
					printf("%d ", b[j]);
			}
		}
		printf("\n");
	}
}

//BÀI 98 - C04009: TACH CHAN LE
int main(){
	int n; scanf("%d", &n);
	int cnt_1 = 0, cnt_2 = 0;
	int a[n];
	int chan[105], le[105];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		if(a[i]%2 == 0)
			chan[cnt_2++] = a[i];
		else
			le[cnt_1++] = a[i];
	}
	for(int i = 0; i < cnt_2; ++i)
		printf("%d ", chan[i]);
	printf("\n");
	for(int i = 0; i < cnt_1; ++i)
		printf("%d ", le[i]);
}

//BÀI 99 - C04010: NHO NHAT VA NHO THU HAI
int main(){
	int n; scanf("%d", &n);
	int a[n+3];
	int min_1 = 1e9, min_2 = 1e9;
	for(int i = 0; i < n; ++i){
		scanf("%d", a+i);
		if(a[i] < min_1)
			min_1 = a[i];
	}
	for(int i = 0; i < n; ++i){
		if(a[i] != min_1 && a[i] < min_2)
			min_2 = a[i];
	}
	printf("%d %d", min_1, min_2);
}

//BÀI 100 - C04011: DEM SO PHAN TU LON HON SO DUNG TRUOC
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int cnt = 0;
		int a[n+3];
		for(int i = 0; i < n; ++i){
			int check = 1;
			scanf("%d", &a[i]);
			for(int j = 0; j <= i; ++j){
				if(a[j] > a[i]){
					check = 0;
					break;
				}
			}
			if(check)
				cnt++;
		}
		printf("%d\n", cnt);
	}
}

//END
