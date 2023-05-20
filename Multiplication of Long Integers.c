
// Q5 DAC mul_longint

#include<stdio.h>

#include<math.h>
void main(){
    int n1,n2,count=0,digit;
    printf("ENter 2 numbers ");
    scanf("%d %d",&n1,&n2);
    int max=(n1>n2)?n1:n2;
    while(max!=0){
        max=max/10;
        count++;
    }
    printf("number of digits are %d\n",count);

    int a,b,c,d;
    a=n1/(int)(pow(10,(count+1)/2));
        printf("a is %d\n",a);
    b=n1%(int)(pow(10,(count+1)/2));
        printf("b is %d\n",b);
    c=n2/(int)pow(10,(count+1)/2);
        printf("c is %d\n",c);
    d=n2%(int)(pow(10,(count+1)/2));
        printf("d is %d\n",d);
    int ans= (a*c*pow(10,count)) + ((a*d)+(b*c))*pow(10,(count+1)/2) +b*d;
    printf("ans is %d",ans);
}

