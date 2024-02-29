#include <stdio.h>
#include <math.h>

//Please copy code blocks of each exercises to another program and F11(Compile&Run)


//Bài 11 : PRIME NUMBER
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	for(int i = 1; i <= test_cases; i++){
		int a, b = 0; scanf("%d", &a);
		if(a<2)
			printf("NO");
		for(int n=2; n <= sqrt(a); ++n){
			if(a%n==0)
				b++;
		}
		if(b!=0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}

//Bài 12 : GREATEST COMMON DIVISOR
	//Cách 1
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	for(int i = 1; i <= test_cases; i++){
		unsigned int a1, a2;
		scanf("%d %d", &a1, &a2);
	    while(a1!=a2)
	    {
	        if(a1 > a2)
	            a1 -= a2;
	        else
	            a2 -= a1;
	    }
	    printf("%d\n",a1);
	}
	return 0;
}

	//Cách 2
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	for(int i = 1; i <= test_cases; i++){
		unsigned int a1, a2, n, gcd;
		scanf("%d %d", &a1, &a2);
		for(n = 1; n <= a1 && n <= a2; ++i){
			if(a1%n==0 && a2%n==0)
				gcd=n;
			}
		printf("%d\n", gcd);
	}
	return 0;
}

	//Cách 3
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	for(int i = 1; i <= test_cases; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		while(b>0){
			a = a%b;
			int tmp = a;
			a = b;
			b = tmp;
		}
		printf("%d", a);
	}
	return 0;
}
*/	

//Bài 13 : PRIME FACTORIZATION
int main(){
	int a, test_cases;
	scanf("%d", &test_cases);
	while(test_cases--)
	{
		unsigned int i;
		scanf("%d", &a);
		for(i = 2; i <= sqrt(a); i++)
		{
			while(a%i == 0)
			{
				printf("%d ", i);
				a /= i;
			}
		}
		if(a > 1){
			printf("%d", a);
		}
		printf("\n");
	}	
	return 0;
}


//Bài 14 : PRODUCT OF DIGITS
int main(){
	unsigned int a, b, product = 1, remainder;
	scanf("%d", &a);
	b = a;
	while(b != 0){
		remainder = b%10;
		product *= remainder;
		b /= 10;
	}
	printf("%d\n", product);
	return 0;		
}

//Bài 15 : ODD AND EVEN DIGITS
int main(){
	int test_cases, i;
	scanf("%d", &test_cases);
	for(i = 1; i <= test_cases; i++){
		unsigned int a;
		int b, c, odd = 0, even = 0;
		scanf("%d", &a);
		b = a;
		while(b != 0){
			c = b%10;
			if(c%2 != 0)
				odd += 1;
			else
				even += 1;
			b /= 10;
			}
		printf("%d %d\n", odd, even);
		}
	return 0;
}

//Bài 16 : SUM OF AN INTERVAL
	//Cách 1
int main(){
	int a, b; scanf("%d %d", &a, &b);
	if(a > b)
		printf("%d\n", ((a+b)*(a-b+1))/2);
	else
		printf("%d\n", ((a+b)*(b-a+1))/2);
	return 0;
}

	//Cách 2
int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	while(b>0)
		a = a%b;
		int tmp = a;
		a = b;
		b = tmp;
	return 0;
}

//bài 17 : PERFECT NUMBER
int main(){
	int a, i, sum = 0;
	scanf("%d", &a);
	for(i = 1; i <= a/2; i++){
		if(a%i == 0)
			sum += i;
	}
	if(sum == a)
		printf("1");
	else
		printf("0");
	return 0;
}

//Bài 18 : STRONG NUMBER
int main()
{
	int num, remainder,sum = 0, a;
	scanf("%d", &num);
	a = num;
	for(a; a>0; a /= 10)
	{
		int i, b = 1;
		remainder = a%10;
		for(i = 1; i <= remainder; i++)
		{
			b *= i;
		}
		sum += b;
	}
	if(sum == num)
		printf("1\n");
	else
		printf("0\n");
	return 0;
}

//Bài 19 : SUM OF DIGITS DIVISIBLE BY 10
	//Cách 1(truyen thong)
int main()
{
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--)
	{
		int a, b, sum = 0;
		scanf("%d", &a);
		if(a>=0)
		{
			while(a!=0)
			{
				b = a%10;
				sum += b;
				a /= 10;
			}
		}
		if(sum%10 == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

	//Cách 2 (sd hàm)
int div10 (int n){
	int sum = 0, m;
	while(n != 0){ m = n%10;
		sum += m; n /= 10;
	}
	if(sum%10 == 0) return 1;
	else return 0;
}

int main(){
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--){
		int a, div;
		scanf("%d", &a);
		if(div10(a)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}


//Bài 20 : PRIME NUMBERS LOWER THAN N

	//Cach 1 (Chay tren code.ptit bi TLE)
int checkPrime(int n)
{
	if(n<2)
		return 0;
	int j = 0;
	for(int i = 2; i < n; i++)
	{
		if(n%i == 0)
			j+=1;
	}
	if(j != 0)
		return 0;
	else
		return 1;
	return checkPrime;
}

void printPrime(int n)
{
	for(int i = 2; i <= n; i++)
		if(checkPrime(i))
			printf("%d\n", i); 
}

int main()
{
	int a; scanf("%d", &a);
	printPrime(a);
	return 0;
}

	//Cach 2 (Su dung toan tu 3 ngoi)
int main()
{
	int so; scanf("%d", &so);
	if(so>2) printf("2\n");
	for(int i = 3; i <= so; i++)
	{
		int prime = 1;
		for(int j = (i == 2 ? 3 : 2); j <= sqrt(i); j++)
		{
			if(i%j == 0)
			{
				prime = 0;
				break;
			}
		}
		if(prime) printf("%d\n", i);
	}
	return 0;
	}




