#include <stdio.h>
#include <math.h>
#include <string.h>
#define ll long long

//BÀI 171 - C04038: SAP XEP CHON - 2
int main(){
	int n; scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);
	for(int i = 0; i < n-1; ++i){
		int min = i;
		for(int j = i+1; j < n; ++j){
			if(a[min] > a[j])
				min = j;
		}
		int tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
		for(int j = 0; j < n; ++j)
			printf("%d ", a[j]);
		printf("\n");
	}
}

//BÀI 172 - C04040: DAY CON LIEN TIEP CO TONG LON NHAT
ll a[100005];

ll max_subarray(ll a[], int n){
	ll max = a[0], mark = a[0];
	for(int i = 1; i < n; ++i){
		mark = (a[i] > mark + a[i] ? a[i] : mark + a[i]);
		max = (max > mark ? max : mark);
	}
	return max;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%lld", &a[i]);
		printf("%lld\n", max_subarray(a,n));
	}
}

//BÀI 173 - C04045: DAY UU THE
int main(){
    int t; scanf("%d", &t);
    while(t--){
        char s[100005];
        scanf("\n");
        gets(s);
        strcat(s, " ");
        int n = strlen(s), d, l, c;
        d = l = c = 0;
        for(int i = 1; i < n; i++){
            if(s[i-1] != ' ' && s[i] == ' '){
                d++;
                if(s[i-1] % 2) l++;
                else c++;
            }
        }
        if((d%2 && (l > c)) || (!(d%2) && (c > l)))
            printf("YES\n");
        else
			printf("NO\n"); 
    }
}

//BÀI 174 - C04047: XEP HANG
void swap(int *xp, int *yp){
	int tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

int main(){
	int n; scanf("%d", &n);
	int a[n+2], b[n+2];
	for(int i = 0; i < n;++i){
		scanf("%d%d", &a[i], &b[i]);
		for(int j = 0; j < i; ++j){
			if(a[i] < a[j]){
				swap(&a[i], &a[j]);
				swap(&b[i], &b[j]);
			}
		}
	}
	int time = a[0] + b[0];
	for(int i = 1; i < n; ++i){
		time = (time > a[i] ? time : a[i]);
		time = time + b[i];
	}
	printf("%d", time);
}

//BÀI 175 - C04048: CHIEU SANG
int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int way[1005] = {0}, lamp[m+2];
	for(int i = 0; i < m; ++i)
		scanf("%d", &lamp[i]);
	for(int i = 0; i < m; ++i){
		int b = lamp[i] - k, c = lamp[i] + k;
		if(b <= 0)
			b = 1;
		if(c > n)
			c = n;
		for(int j = b; j <= c; ++j)
			way[j] = 1;
	}
	int st = 0;
	for(int i = 1; i <= n; ++i){
		int cnt = 0;
		while(way[i] == 0 && i <= n){
			cnt++;
			i++;
		}
		int p = cnt/(2*k + 1);
		if(cnt%(2*k + 1) == 0)
			st += p;
		else
			st += p + 1;
		if(cnt != 0)
			i--;
	}
	printf("%d", st);
}

//BÀI 176 - C04050: TAP HOP SO NGUYEN
int main(){
	int n, m; scanf("%d%d", &n, &m);
	int a[105], b[105], ratio_a[1005] = {0}, ratio_b[1005] = {0};
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		ratio_a[a[i]]++;
	}
	for(int i = 0; i < m; ++i){
		scanf("%d", &b[i]);
		ratio_b[b[i]]++;
	}
	n = 0, m = 0;
	for(int i = 0; i < 1005; ++i){
		if(ratio_a[i]) a[n++] = i;
		if(ratio_b[i]) b[m++] = i;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(a[i] == b[j]){
				printf("%d ", b[j]);
				b[j] = a[i] = 0;
				break;
			}
		}
	}
	printf("\n");
	for(int i = 0; i < n; ++i)
		if(a[i]) printf("%d ", a[i]);
	printf("\n");
	for(int i = 0; i < m; ++i)
		if(b[i]) printf("%d ", b[i]);
}

//BÀI 177 - C05006: CHUYEN DOI HAI HANG TRONG MA TRAN
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int a[n+2][m+2];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);
	}
	int x, y;
	scanf("%d%d", &x, &y);
	for(int i = 0; i < m; ++i){
		int tmp = a[x-1][i];
		a[x-1][i] = a[y-1][i];
		a[y-1][i] = tmp;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

//BÀI 178 - C05007: CHUYEN DOI HAI COT TRONG MA TRAN
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int a[n+2][m+2];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);
	}
	int x, y;
	scanf("%d%d", &x, &y);
	for(int i = 0; i < n; ++i){
		int tmp = a[i][x-1];
		a[i][x-1] = a[i][y-1];
		a[i][y-1] = tmp;
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

//BÀI 179 - C05008: LOAI BO HANG VA COT CO TONG LON NHAT RA KHOI MA TRAN
int main(){
	int t; scanf("%d", &t);
	int k = 1;
	while(t--){
		int n, m;
		scanf("%d%d", &m, &n);
		int sum_row = -1e9, sum_col = -1e9;
		int mark_row = 0, mark_col = 0;
		int a[m+2][n+2];
		for(int i = 0; i < m; ++i){
			int cnt = 0;
			for(int j = 0; j < n; ++j){
				scanf("%d", &a[i][j]);
				cnt += a[i][j];
			}
			if(cnt > sum_row){
				sum_row = cnt;
				mark_row = i;
			}
		}
		for(int j = 0; j < n; ++j){
			int cnt = 0;
			for(int i = 0; i < m; ++i){
				if(i != mark_row)
					cnt += a[i][j];
			}
			if(cnt > sum_col){
				sum_col = cnt;
				mark_col = j;
			}
		}
		printf("Test %d:\n", k++);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(i != mark_row && j != mark_col)
					printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}

//BÀI 180 - C05009: CHUYEN DOI HAI DUONG CHEO
void swap(int *xp, int *yp){
	int tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

int main(){
	int m; scanf("%d", &m);
	int a[m+2][m+2];
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= m; ++j)
			scanf("%d",&a[i][j]);
	}
	for(int i = 1; i <= m; ++i){
		if(i != m-i+1)
			swap(&a[i][i], &a[i][m-i+1]);
	}
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= m; ++j)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

//END
