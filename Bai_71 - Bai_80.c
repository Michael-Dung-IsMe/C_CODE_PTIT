#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//BÀI 71: SPLITTED IN HALF
int main(){
	int T; scanf("%d", &T);
	while(T--){
		long long n; scanf("%lld", &n);
		long long x = log10(n)+1;
		int cnt = 0;
		long long m = n;
	//Kiem tra so n co chua cac so khac 0,1,8,9 khong?
		while(m > 0){
			if(m%10 != 0 && m%10 != 1 && m%10 != 8 && m%10 != 9)
				cnt++;
			m /= 10;
		}
		if(cnt != 0 || n == 0){	//neu co --> INVALID --> T--
			printf("INVALID\n");
			continue;
		}
	//Neu khong --> Tien hanh in n (Dung cach in tu trai -> phai = phep chia nguyen truoc -> phep chia du de luoc di so dau tien)
		cnt = 0;
		while(x >= 0){
		//cnt != 0 de dam bao cac so 0 dung dau khong duoc in ra, va day co so khac 0
			if((n/(long long)pow(10,x) == 0 || n/(long long)pow(10,x) == 8 || n/(long long)pow(10,x) == 9) && cnt != 0)
				printf("0");
			if(n/(long long)pow(10,x) == 1){
				printf("1");
				cnt++;
			}
			n %= (long long)pow(10,x);
			x--;
		}
		//Kiem tra xem so chi co so 0 khong
		if(cnt == 0)
			printf("INVALID\n");
		else
			printf("\n");
	}
}

//BÀI 72: NUMBERED TRIANGLE
int main(){
	int n; scanf("%d", &n);
	int cnt = 1;
	for(int i = 1; i <= n; i++){
		int a[100];
		if(i%2 != 0){
			for(int j = 0; j < i; j++){
				a[j] = cnt++;
				printf("%d ", a[j]);
			}
		}
		else{
			for(int j = i-1; j >= 0; j--)
				a[j] = cnt++;
			for(int j = 0; j < i; j++)
				printf("%d ", a[j]);
		}
		printf("\n");
	}
}

//BÀI 73: PRIME NUMBERS IN AN ARRAY
int checkP(int n){
	if(n == 2 || n == 3)
		return 1;
	if(n == 1 || n%2 == 0 || n%3 == 0)
		return 0;
	for(int i = 5; i*i <= n; ){
		if(n%i == 0 || n%(i+2) == 0)
			return 0;
		i+=6;
	}
	return 1;
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int n; scanf("%d", &n);
		int a[n];
		for(int i = 0; i < n; i++)
			scanf("%d", a+i);
		for(int i = 0; i < n; i++){
			if(checkP(a[i]) == 1)
				printf("%d ", *(a+i));
		}
		printf("\n");
	}
	return 0;
}

//BÀI 74: HIGHEST NUMBER
int main(){
	int T; scanf("%d", &T);
	while(T--){
		int n; scanf("%d", &n);
		int a[n];
		for(int i = 0; i < n; i++)
			scanf("%d", a+i);
		int max = -1e6;
		for(int i = 0; i < n; i++){
			if(max < a[i])
				max = a[i];
		}
		printf("%d\n", max);
		for(int j = 0; j < n; j++){
			if(a[j] == max)
				printf("%d ", j);
		}
		printf("\n");
	}
	return 0;
}

//BÀI 75: PRODUCT OF DIAGONAL MATRIX
int main(){
	int T; scanf("%d", &T);
	for(int k = 1; k <= T; k++){
		int n; scanf("%d", &n);
		int a[25][25], b[25][25];
		for(int i = 0; i < n; i++){
			int cnt = 1;
			for(int j = 0; j < i+1; j++)
				a[i][j] = cnt++;
			for(int j = i+1; j < n; j++)
				a[i][j] = 0;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				b[i][j] = a[j][i];
		}
		printf("Test %d:\n", k);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int sum = 0;
				for(int m = 0; m < n; m++){
					sum = sum + (a[i][m]*b[m][j]);
					}
				printf("%d ", sum);
				sum = 0;
			}
			printf("\n");
		}
	}
	return 0;
}

//BÀI 76: PRETTY NUMBERS 1
char s[1001];

int main(){
	int T; scanf("%d", &T);
	while(T--){
		scanf("%s", s);
		int leng = strlen(s);
		int check = 0;
		for(int i = 0; i <= (leng-1)/2; i++){
			if((int)s[i] != (int)s[leng-1-i] || (int)(s[i] - '0')%2 != 0){
				printf("NO\n");
				check = 1;
				break;
			}
		}
		if(check == 1){
			continue;
		}
		printf("YES\n");
	}
	return 0;
}

//BÀI 77: PRETTY NUMBERS 2
char s[501];

int main(){
	int T; scanf("%d", &T);
	while(T--){
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

//BÀI 78: SUM OF TWO BIG INTEGERS
void swapArr(int a[], int n){
	for(int i = 0; i < n/2; i++){
		int tmp = a[i];
		a[i] = a[n-1-i];
		a[n-1-i] = tmp;
	}
}

int main(){
	int t; scanf("%d", &t);
	getchar();
	while(t--){
		char c1[505], c2[505];
		gets(c1); gets(c2);
		int res[510];
		int k, sum = 0;
		int n1 = strlen(c1), n2 = strlen(c2);
		k = fmax(n1,n2);
		int u[505] = {0}, v[505] = {0};
		for(int i = 0; i < n1; i++)
			u[i] = c1[i] - '0';
		for(int i = 0; i < n2; i++)
			v[i] = c2[i] - '0';
		swapArr(u,n1);
		swapArr(v,n2);
		for(int i = 0; i < k-1; i++){
			res[i] = u[i] + v[i] + sum;
			if(res[i] > 9){
				res[i] -= 10;
				sum = 1;
			}
			else
				sum = 0;
		}
		res[k-1] = u[k-1] + v[k-1] + sum; 
		for(int i = k-1; i >= 0; i--)
			printf("%d", res[i]);
		printf("\n");
	}
}

//BÀI 79: ROMAN NUMERALS
int val[] = {1, 5, 10, 50, 100, 500, 1000};
char roman[] = "IVXLCDM";

int pos(char c){
	for(int i = 0; i < 7; i++){
		if(roman[i] == c)
		  return i;
	}
}
	
int findS(char c[]){
	int n = strlen(c);
	int sum = val[pos(c[n-1])];
	for(int i = n-1; i > 0; i--){
		int pos1 = pos(c[i]);
		int pos2 = pos(c[i-1]);
		if(val[pos1] <= val[pos2])
			sum += val[pos2];
		else
			sum -= val[pos2];
	}
	return sum;
}

int main(){
	int t; scanf("%d", &t);
	getchar();
	while(t--){
		char c1[1005];
		gets(c1);
		for(int i = 0; i < strlen(c1); i++)
			c1[i] = toupper(c1[i]);
		printf("%d\n", findS(c1));
	}
}

//BÀI 80: CHANGING BASES : chuyen so tu he co so 10 --> he b (2 <= b <= 36)
const char change[] = {
			'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H',
			'I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
	};

int main(){
	int t; scanf("%d", &t);
	while(t--){
		char a[100005];
		int n, b;
		scanf("%d%d", &n, &b);
		if(n == 0)
			printf("0\n");
		else{
			int cnt = 0;
			while(n != 0){
				int tmp = n%b;
				n /= b;
				a[cnt++] = change[tmp];
			}
			a[cnt] = '\0';
			for(int i = 0; i < cnt/2; i++){
				int temp = a[i];
				a[i] = a[cnt-1-i];
				a[cnt-1-i] = temp;
			}
			puts(a);
		}
	}
	return 0;
}



