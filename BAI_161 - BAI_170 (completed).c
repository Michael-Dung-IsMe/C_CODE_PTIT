#include <stdio.h>
#include <math.h>
#include <string.h>
#define ll long long

//BÀI 161 - C03058: LCM CUA N SO NGUYEN DUONG DAU TIEN
	//Tim gcd cua n so nguyen dau tien --> thuat toan euclide tim lcm = (tich n so dau tien) / gcd(n so dau tien)
ll gcd(ll a, ll b){
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		ll n; scanf("%lld", &n);
		ll lcm = 1;
		for(ll i = 2; i <= n; ++i)
			lcm = (i*lcm)/gcd(i,lcm);
		printf("%lld\n", lcm);
	}
}

//BÀI 162 - C04019: SO XUAT HIEN NHIEU LAN NHAT TRONG DAY
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int max = -1, cnt = 0, check = 0;
		int a[n+3], b[30005] = {0};
		for(int i = 0; i < n; ++i){
			scanf("%d", a+i);
			b[a[i]]++;
			if(b[a[i]] > max)
				max = b[a[i]];
		}
		for(int i = 0; i < n; ++i){
			if(b[a[i]] == max)
				printf("%d ", a[i]);
			b[a[i]] = 0;
		}
		printf("\n");
	}
}

//BÀI 163 - C04025: SAP XEP CHAN LE
void sapxep(int a[], int n){
	for(int i = 0; i < n; ++i){
		for(int j = i+1; j < n; ++j){
			if(a[i] > a[j]){
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

int main(){
	int n; scanf("%d", &n);
	int even = 0, odd = 0;
	int a[n+2], chan[n+2], le[n+2];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		if(a[i]%2)
			le[odd++] = a[i];
		else
			chan[even++] = a[i];
	}
	sapxep(chan, even);
	sapxep(le, odd);
	for(int i = 0; i < even; ++i)
		printf("%d ", chan[i]);
	for(int i = 0; i < odd; ++i)
		printf("%d ", le[i]);
}

//BÀI 164 - C04026: SAP XEP DOI CHO TRUC TIEP
int main(){
	int n; scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);
	for(int i = 0; i < n-1; ++i){
		printf("Buoc %d: ", i+1);
		for(int j = i+1; j < n; ++j){
			if(a[i] > a[j]){
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
		for(int j = 0; j < n; ++j)
			printf("%d ", a[j]);
		printf("\n");
	}
}

//BÀI 165 - C04027: SAP XEP CHON
int main(){
	int n; scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);
	for(int i = 0; i < n-1; ++i){
		printf("Buoc %d: ", i+1);
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

//BÀI 166 - C04028: SAP XEP CHEN
int main(){
	int n; scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);
	for(int i = 0; i < n; ++i){
		printf("Buoc %d: ", i);
		int j = i;
		while(j && a[j-1] > a[j]){
			int tmp = a[j-1];
			a[j-1] = a[j];
			a[j] = tmp;
			j--;
		}
		for(int k = 0; k <= i; ++k)
			printf("%d ", a[k]);
		printf("\n");
	}
}

//BÀI 167 - C04029: SAP XEP NOI BOT
int main(){
	int n; scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);
	for(int i = 0; i < n-1; ++i){
		int cnt = 0;
		for(int j = 0; j < n-1-i; ++j){
			if(a[j] > a[j+1]){
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
				cnt++;
			}
		}
		if(cnt == 0)
			break;
		printf("Buoc %d: ", i+1);
		for(int j = 0; j < n; ++j)
			printf("%d ", a[j]);	
		printf("\n");
	}
}

//BÀI 168 - C04030: TRON HAI DAY VA SAP XEP
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
		int a[n+2], b[n+2];
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
			for(int j = 0; j < i; ++j){
				if(a[i] < a[j])
					swap(&a[i], &a[j]);
			}
		}
		for(int i = 0; i < n; ++i){
			scanf("%d", &b[i]);
			for(int j = 0; j < i; ++j){
				if(b[i] > b[j])
					swap(&b[i], &b[j]);
			}
		}
		printf("Test %d:\n", k++);
		for(int i = 0; i < 2*n; ++i){
			if(i%2)
				printf("%d ", b[i/2]);
			else
				printf("%d ", a[i/2]);
		}
		printf("\n");
	}
}

//BÀI 169 - C04031: DOAN TANG DAI NHAT
int main(){
	int t; scanf("%d", &t);
	int k = 1;
	while(t--){
		int n; scanf("%d", &n);
		int a[n+3];
		int cnt = 1, max = -1e9;
		scanf("%d", &a[0]);
		printf("Test %d:\n", k++);
		for(int i = 1; i < n; i++){
			scanf("%d", &a[i]);
			if(a[i-1] < a[i])
				++cnt;
			else{
				if(cnt > max)
					max = cnt;
				cnt = 1;
			}
		}
		printf("%d\n", max);
		cnt = 1;
		for(int i = 1; i < n; ++i){
			if(a[i-1] < a[i]){
				cnt++;
				if(cnt == max){
					for(int j = i-max+1; j < i+1; ++j)
						printf("%d ", a[j]);
					cnt = 1;
					printf("\n");
				}
			}
			else cnt = 1;
		}
	}
}

//BÀI 170 - C04036: DOI TIEN
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int step = 0;
		int tien[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
		for(int i = 9; i >= 0; --i){
			while(n >= tien[i]){
				step++;
				n -= tien[i];
			}
		}
		printf("%d\n", step);
	}
}

//END
