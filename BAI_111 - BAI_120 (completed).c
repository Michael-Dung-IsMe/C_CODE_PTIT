#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//BÀI 111 - C04023: DAY XEP TANG
int main(){
	int n; scanf("%d", &n);
	int a[n+5];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		for(int j = 0; j < i; ++j){
			if(a[i] < a[j]){
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	for(int i = 0; i < n; ++i)
		printf("%d ", a[i]);
}

//BÀI 112 - C04024: DAY XEP GIAM
int main(){
	int n; scanf("%d", &n);
	int a[n+5];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		for(int j = 0; j < i; ++j){
			if(a[i] > a[j]){
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	for(int i = 0; i < n; ++i)
		printf("%d ", a[i]);
}

//BÀI 113 - C04033: LOAI BO TRUNG NHAU
int main(){
	int n; scanf("%d", &n);
	int a[n+5], b[105] = {0};
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for(int i = 0; i < n-1; ++i){
		if(b[i] == 0){
			for(int j = i+1; j < n; ++j){
				if(a[i] == a[j])
					b[j] = 1;
			}
		}
	}
	for(int i = 0; i < n; ++i){
		if(b[i] == 0)
			printf("%d ", a[i]);
	}
}

//BÀI 114 - C04034: SO DUNG DAU
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n, cnt = 0;
		scanf("%d", &n);
		int a[n+5], b[1005] = {0};
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for(int i = 0; i < n; ++i){
			int  check = 0;
			for(int j = i+1; j < n; ++j){
				if(a[i] <= a[j]){
					check = 1;
					break;
				}
			}
			if(check == 0)
				b[cnt++] = a[i];
		}
		for(int i = 0; i < cnt; ++i)
			printf("%d ", b[i]);
		printf("\n");
	}
}

//BÀI 115 - C04037: LIET KE PHAN TU XUAT HIEN > 1 LAN
int main(){
	int n; scanf("%d", &n);
	int a[n+2], b[105] = {0}, res[105] = {0};
	int dem = 0;
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i){
		int cnt = 1;
		if(b[i] == 0){
			for(int j = i+1; j < n; ++j){
				if(a[i] == a[j]){
					b[j] = 1;
					cnt++;
				}
			}
		}
		if(cnt > 1)	res[dem++] = a[i];
	}
	printf("%d\n", dem);
	for(int i = 0; i < dem; ++i)
		printf("%d ", res[i]);
	printf("\n");
}

//BÀI 116 - C05001: MA TRAN CHUYEN VI
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int a[n+2][m+2];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);
	}
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j)
			printf("%d ", a[j][i]);
		printf("\n");
	}
}

//BÀI 117 - C05005: LOAI BO HANG VA COT DAU TIEN RA KHOI MA TRAN
int main(){
	int t; scanf("%d", &t);
	int cnt = 1;
	while(t--){
		int n, m;
		scanf("%d%d", &n, &m);
		int a[n+2][m+2];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j)
				scanf("%d", &a[i][j]);
		}
		printf("Test %d:\n", cnt++);
		for(int i = 1; i < n; ++i){
			for(int j = 1; j < m; ++j)
				printf("%d ", a[i][j]);
			printf("\n");
		}
	}
}

//BÀI 118 - C06003: DEM SO TU TRONG XAU
int main(){
	int t; scanf("%d", &t);
	getchar();
	while(t--){
		char s1[105], res[50][20];
		gets(s1);
		int cnt = 0;
		char *spr = strtok(s1, " ");
		while(spr != NULL){
			strcpy(res[cnt++], spr);
			spr = strtok(NULL, " ");
		}
		printf("%d\n", cnt);
	}
}

//BÀI 119 - C06004: DEM KI TU
int main(){
	char s1[1005];
	gets(s1);
	int so = 0, chu = 0, khac = 0;
	for(int i = 0; i < strlen(s1); ++i){
		int k = (int)s1[i];
		if((k >= 65 && k <= 90) || (k >= 97 && k <= 122))
			chu++;
		else if(k >= 48 && k <= 57)
			so++;
		else
			khac++;
	}
	printf("%d %d %d", chu, so, khac);
}

//BÀI 120 - C06007: LOAI BO TU TRONG XAU
int main(){
	char s1[105], s2[105], res[50][50];
	gets(s1);
	scanf("\n");
	gets(s2);
	for(int i = 0; i < strlen(s1); ++i)
	    s1[i] = tolower(s1[i]);
	int cnt = 0, k = 1;
	char *spr = strtok(s1, " ");
	while(spr != NULL){
		strcpy(res[cnt++], spr);
		spr = strtok(NULL, " ");
	}
	for(int i = 0; i < cnt; ++i){
		if(strcmp(s2, res[i]))
			printf("%s ", res[i]);
	}
}

//END
