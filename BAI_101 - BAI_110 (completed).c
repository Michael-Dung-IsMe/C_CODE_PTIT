#include <stdio.h>
#include <math.h>

//BÀI 101 - C04012: XUAT HIEN NHIEU HON 1 LAN
int main(){
	int n; scanf("%d", &n);
	int a[n+2], b[105] = {0};
	int dem = 0;
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i){
		int cnt = 1, check = 0;
		if(b[i] == 0){
			for(int j = i+1; j < n; ++j){
				if(a[i] == a[j]){
					b[j] = 1;
					cnt++;
				}
			}
		}
		if(cnt > 1)
			printf("%d ", a[i]);
		else
			dem++;
	}
	if(dem == n)
		printf("0");
}

//BÀI 102 - C04013: XUAT HIEN DUNG 1 LAN
int main(){
	int n; scanf("%d", &n);
	int a[n+2], b[105] = {0}, res[105] = {0};
	int dem = 0;
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i){
		int cnt = 0, check = 0;
		if(b[i] == 0){
			cnt = 1;
			for(int j = i+1; j < n; ++j){
				if(a[i] == a[j]){
					b[j] = 1;
					cnt++;
				}
			}
		}
		if(cnt == 1)
			res[dem++] = a[i];
	}
	printf("%d\n", dem);
	for(int i = 0; i < dem; ++i)
		printf("%d ", res[i]);
}

//BÀI 103 - C04014: DEM SO LAN XUAT HIEN 1
int main(){
	int n; scanf("%d", &n);
	int a[n+2], b[105] = {0}, res[105] = {0};
	int dem = 0;
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i){
		int cnt = 0;
		if(b[i] == 0){
			cnt = 1;
			for(int j = i+1; j < n; ++j){
				if(a[i] == a[j]){
					b[j] = 1;
					cnt++;
				}
			}
		res[dem++] = cnt;
		}
	}
	dem = 0;
	for(int i = 0; i < n; ++i){
		if(b[i] == 0)
			printf("%d %d\n", a[i], res[dem++]);
	}
}

//BÀI 104 - C04015: DEM SO LAN XUAT HIEN 2
int main(){
	int t; scanf("%d", &t);
	int k = 1;
	while(t--){
		int n; scanf("%d", &n);
		int a[n+2], b[105] = {0}, res[105] = {0};
		int dem = 0;
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for(int i = 0; i < n; ++i){
			int cnt = 0;
			if(b[i] == 0){
				cnt = 1;
				for(int j = i+1; j < n; ++j){
					if(a[i] == a[j]){
						b[j] = 1;
						cnt++;
					}
				}
			res[dem++] = cnt;
			}
		}
		dem = 0;
		printf("Test %d:\n", k++);
		for(int i = 0; i < n; ++i){
			if(b[i] == 0)
				printf("%d xuat hien %d lan\n", a[i], res[dem++]);
		}
		printf("\n");
	}
}

//BÀI 105 - C04016: DEM CAC SO NGUYEN TO TRONG DAY
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

void swap(int *xp, int *yp){
	int tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

int main(){
	int t; scanf("%d", &t);
	int k = 1;
	while(t--){
		int n; scanf("%d", &n);
		int a[n+2], b[105] = {0}, res[105] = {0};
		int dem = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
			for(int j = 0; j <= i; ++j){
				if(a[i] < a[j])
					swap(&a[i], &a[j]);
			}
		}
		for(int i = 0; i < n-1; ++i){
			if(checkP(a[i])){
				int cnt = 1;
				while(a[i] == a[i+1]){
					a[i] = 1;
					cnt++;
					i++;
				}
				b[dem] = a[i];
				res[dem++] = cnt;
			}
		}
		printf("Test %d:\n", k++);
		for(int i = 0; i < dem; ++i){
				printf("%d xuat hien %d lan\n", b[i], res[i]);
		}
		printf("\n");
	}
}

//BÀI 106 - C04017: LIET KE SO NGUYEN TO TRONG DAY
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
	int n; scanf("%d", &n);
	int a[n+2], res[105] = {0};
	int dem = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		if(checkP(a[i]))
			res[dem++] = a[i];
	}
	printf("%d ", dem);
	for(int i = 0; i < dem; ++i)
		printf("%d ", res[i]);
}

//BÀI 107 - C04018: SO CAP BANG NHAU TRONG DAY
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int a[n+3];
		for(int i = 0; i < n; ++i)
			scanf("%d", a+i);
		int cnt = 0;
		for(int i = 0; i < n-1; ++i){
			while(a[i] == a[i+1]){
				cnt++;
				i++;
			}
		}
		printf("%d\n", cnt);
	}
}

//BÀI 108 - C04020: DICH TRAI
int main(){
	int n, k; scanf("%d", &n);
	int a[n+3];
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	for(int i = k; i < n; ++i)
		printf("%d ", a[i]);
	for(int i = 0; i < k; ++i)
		printf("%d ", a[i]);
}

//BÀI 109 - C04021: DICH PHAI
int main(){
	int n, k; scanf("%d", &n);
	int a[n+3];
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	for(int i = n-k; i < n; ++i)
		printf("%d ", a[i]);
	for(int i = 0; i < n-k; ++i)
		printf("%d ", a[i]);
}

//BÀI 110 - C04022: LON NHAT VA LON THU HAI
int main(){
	int n; scanf("%d", &n);
	int a[n+5];
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int max1 = a[1], max2 = -1e9;
	for(int i = 2; i <= n; ++i){
		if(max1 < a[i])
			max1 = a[i];
	}
	for(int i = 0; i < n; ++i){
		if(max2 < a[i] && a[i] < max1)
			max2 = a[i];
	}
	printf("%d %d", max1, max2);
}

//END
