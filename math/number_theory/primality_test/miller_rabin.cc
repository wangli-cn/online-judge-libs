#include <iostream>

/* Miller-Rabin primality test, iteration signifies the accuracy of the test */
bool Miller(long long p,int iteration)
{
    if(p<2){
        return false;
    }

    if(p!=2 && p%2==0){
        return false;
    }

    long long s=p-1;
    while(s%2==0){
        s/=2;
    }

    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }

    return true;
}


int main()
{
    return 0;
}
