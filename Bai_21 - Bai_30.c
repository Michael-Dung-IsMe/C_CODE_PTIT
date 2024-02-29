#include <stdio.h>
#include <math.h>

//BÀI 21: LISTING N FIRST PRIME NUMBERS
void checkPrime(int n){
	int a, i = 2, dem, count = 1;
	while(count <= n)
	{
		dem = 0;
		for(a = 2; a <= sqrt(i); a++)
		{
			if(i%a == 0)
			{
				dem = 1;
				break;
			}
		}
		if(dem == 0)
		{
			printf("%d\n", i);
			count ++;
		}
		i++;
	}
}

int main(){
	int so; scanf("%d", &so);
	checkPrime(so);
	return 0;
}

//BÀI 22: GCD - LCM
long long int gcd(long long int a, long long int b){
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

long long int lcm(long long int a, long long int b){
	return (a*b)/gcd(a,b);
}

int main(){
	unsigned long long int a, b;
	scanf("%llu %llu", &a, &b);
	printf("%llu\n", gcd(a,b));
	printf("%llu", lcm(a,b));
	return 0;
}

//BÀI 23: PASCAL TRIANGLE
long long pascal(long long k, long long n);

int main(){
	long long n, i, k;
	scanf("%lld", &n);
	for(i = 0; i < n; i++){
		for(k = 0; k <= i; k++){
			printf("%lld ", pascal(k,i));
		}
		printf("\n");
	}
	return 0;
}

long long pascal(long long k, long long n){
	if(k == 0 || k == n){
		return 1;
	}
	else{
		return pascal(k-1, n-1) + pascal(k,n-1);
	}
}

//BÀI 24: PALINDROMIC ARRAY
int main(){
	int T; scanf("%d", &T);
	for(int i = 1; i <= T; ++i){
		int n; scanf("%d", &n);
		int A[n];
		for(int j = 0; j < n; j++)
			scanf("%d", &A[j]);
		if(A[0] == A[n-1])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

//BÀI 25: REVERSE AN ARRAY
int main(){
	int n; scanf("%d", &n);
	int A[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for(int j = n-1; j >= 0; j--){
		printf("%d ", A[j]);
	}
	return 0;
}

//BÀI 26: FIBONACCI NUMBER
int main(){
	int T; scanf("%d", &T);
	for(int i = 1; i <= T; ++i){
		unsigned long long A[93];
		for(long long j = 2; j < 93; j++){
			A[0] = 1;
			A[1] = 1;
			A[j] = A[j-1] + A[j-2];
		}
		int n; scanf("%d", &n);
		printf("%lld\n", A[n-1]);
	}
	return 0;
}

//BÀI 27: SPLITTING ODD AND EVEN
int main(){
	int n; scanf("%d", &n);
	int A[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	int chan[100], j = 0, k = 0, le[100];
	for(int i = 0; i < n; i++){
		if(A[i]%2 == 0){
			chan[j] = A[i];
			j+=1;
		}
		else{
			le[k] = A[i];
			k+=1;
		}
	}
	for(int i = 0; i < j; i++){
		printf("%d ", chan[i]);
	}
	printf("\n");
	for(int i = 0; i < k; i++){
		printf("%d ",le[i]);
	}
}

//BÀI 28: APPEARING EXACTLY ONCE

//Cách 1:
	//1. Sap xep lai day theo chieu tang
	//2. dung bien cnt ktra
		//neu a[i] == a[i+1] / a[i] == a[i-1]
		//=> cnt++;
		//else => in luon
int main(void){
	void swap(int*xp, int *yp);
	void bubble_ascend(int A[], int n);
	void unique_number(int A[], int n);
	
	int main(){
		int n; scanf("%d", &n);
		int A[n];
		for(int i = 0; i < n; i++){
			scanf("%d", &A[i]);
		}
		bubble_ascend(A,n);
		unique_number(A,n);
		return 0;
	}
	
	void swap(int *xp, int *yp){
		int swp = *xp;
		*xp = *yp;
		*yp = swp;
	}
	
	void bubble_ascend(int A[], int n){
		int i, j;
		for(i = 0; i < n; i++){
			for(j = n - 1; j > i; j--){
				if(A[j] < A[j-1])
					swap(&A[j], &A[j-1]);
			}
		}
	}
	
	void unique_number(int A[], int n){
		int cnt = 0, check = 0;
		int B[100];
		for(int i = 0; i < n; i++){
			if(A[i] == A[i+1] || A[i] == A[i-1])
				cnt++;
			else{
				B[check] = A[i];
				check++;
			}
		}
		printf("%d\n", n-cnt);
		for(int i = 0; i < check; i++)
			printf("%d ", B[i]);
	}
}

//Cách 2: Hoi Le Minh Duc
int main(){
  int n;
  scanf("%d", &n);
  int A[n];
  for (int i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  int counts[100] = {0};
  for (int i = 0; i < n; i++){
  	counts[A[i]]++;
  }
  int unique_elements[n];
  int num_unique_elements = 0;
  for (int i = 0; i < 100; i++){
    if (counts[i] == 1)
		unique_elements[num_unique_elements++] = i;
  	}
  printf("%d\n", num_unique_elements);
  for (int i = 0; i < num_unique_elements; i++){
	printf("%d ", unique_elements[i]);
  }
  printf("\n");
  return 0;
}

//BÀI 29: COUNTING APPEARANCES 1
void check1(int A[], int n){
	for(int i = 0; i < n; i++){
		int cnt = 0;
		int check = 0;
		for(int j = 0; j < n; j++){
			if(A[i] == A[j])
				cnt++;
		}
		for(int k = i-1; k >= 0; k--){
			if(A[i] == A[k])
				check = 1;
		}
		if(check == 0)
			printf("%d %d\n", A[i], cnt);
	}
}

int main(){
	int n; scanf("%d", &n);
	int A[101];
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	check1(A,n);
}

//BÀI 30: SHIFTING LEFT
int main(){
	int n; scanf("%d", &n);
	int A[200];
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	int k;
	scanf("%d", &k);
	for(int j = 0; j < k; j++)
		A[n+j] = A[j];
	for(int j = k; j < n+k; j++)
		printf("%d ", A[j]);
	return 0;
}

