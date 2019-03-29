/*
	input: a,b two big number, digit of number if not bigger than 1e5
	output: a*b
*/
#include <bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
const int N=2e5+10;
int n,m;
int rev[N],ans[N];
char a[N],b[N];
struct Complex{
	double real,image;
	Complex(double _real=0,double _image=0):real(_real),image(_image){}
	Complex operator + (const Complex rhs){
		return Complex(real+rhs.real,image+rhs.image);
	}
	Complex operator - (const Complex rhs){
		return Complex(real-rhs.real,image-rhs.image);
	}
	Complex operator * (const Complex rhs){
		return Complex(real*rhs.real-image*rhs.image,real*rhs.image+image*rhs.real);
	}
}A[N],B[N];



int read(){
	int len_a,len_b;
	scanf("%s %s",a,b);
//	puts(a);
//	puts(b);
	len_a=strlen(a);
	len_b=strlen(b);
	int n,m,l;
	m=len_a+len_b;
	for(int i=0;i<len_a;i++)
		A[i].real=a[len_a-i-1]-'0';
//	for(int i=0;i<len_a;i++)
//		printf("%.lf ",A[i].real);
//	puts("");
	for(int i=0;i<len_b;i++)
		B[i].real=b[len_b-i-1]-'0';
	l=0;
	for(n=1;n<m;n<<=1)l++;
	for(int i=0;i<n;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	return n;
} 

void FFT(Complex a[],int n,int sign){
//	for(int i=0;i<n;i++)
//		printf("%lf ",a[i].real);puts("");
	
	for(int i=0;i<n;i++)
		if(rev[i]<i){
			swap(a[i],a[rev[i]]);
		}
//	for(int i=0;i<n;i++)
//		printf("%lf ",a[i].real);puts("");

	for(int i=2;i<=n;i<<=1){
		Complex dw(cos(2*pi/i),sin(2*pi*sign/i));
		for(int j=0;j<n;j+=i){
			Complex w(1,0);
			for(int k=0;k<(i>>1);k++){
				Complex u=a[j+k]; //y_k(0)
				Complex v=a[j+k+(i>>1)]*w; //y_k(1) * w 
				a[j+k]=u+v;
				a[j+k+(i>>1)]=u-v;
				w=w*dw;
			}
		}
	}
	if(sign==-1)
		for(int i=0;i<n;i++){
//			printf("%lf ",a[i].real);
//			ans[i]=(int)round(a[i].real/n); 
			ans[i]=(int)(a[i].real/n+0.5);
		}

}
void print_FFT(int n){
	for(int i=0;i<n;i++)
		if(ans[i]>=0){
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
	int m=n-1;
	while(!ans[m])m--;
	for(int i=m;~i;i--)
		printf("%d",ans[i]);
	printf("\n");
}
int main(){	
	int n=read();
	FFT(A,n,1);
	FFT(B,n,1);
	for(int i=0;i<n;i++){
		A[i]=A[i]*B[i];
	}
	FFT(A,n,-1);
	print_FFT(n);		
}
