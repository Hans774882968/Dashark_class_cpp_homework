#include <iostream>
#include <cstring>
using namespace std;
class Prime {
    public:
        static const int SZ = 10000;
        static int primes[SZ/5];
        static char notpr[SZ+10];
        static int psz;
        Prime(int num);
        ~Prime(){}
        static void pr_init();
        int getN(){return mNum;}
        bool isPrime();
        
        Prime sumBit();
        Prime multiBit();
        Prime sqaureSumBit();
    private:
        const int mNum;
};

Prime::Prime(int num):mNum(num){}

void Prime::pr_init(){ //欧拉筛
    memset(primes,0,sizeof primes);
    memset(notpr,0,sizeof notpr);
    for(int i = 2;i <= Prime::SZ;i++){
        if(!notpr[i]) primes[psz++] = i;
        for(int j = 0;j < psz && primes[j] <= Prime::SZ / i;j++){
            notpr[primes[j] * i] = '1';
            if(i % primes[j] == 0) break;
        }
    }
}

bool Prime::isPrime(){ //only support 0-SZ
    if(mNum < Prime::primes[0] || mNum > Prime::primes[Prime::psz-1]) return false;
    return !Prime::notpr[mNum];
}

Prime Prime::sumBit(){
    int sum = 0;
    for(int tmp = mNum;tmp;tmp /= 10){
        sum += tmp % 10;
    }
    Prime ret(sum);
    return ret;
}

Prime Prime::multiBit(){
    int mul = 1;
    for(int tmp = mNum;tmp;tmp /= 10){
        mul *= tmp % 10;
    }
    Prime ret(mul);
    return ret;
}

Prime Prime::sqaureSumBit(){
    int squ = 0;
    for(int tmp = mNum;tmp;tmp /= 10){
        squ += (tmp % 10) * (tmp % 10);
    }
    Prime ret(squ);
    return ret;
}

int Prime::psz = 0;//静态成员初始化
int Prime::primes[Prime::SZ / 5] = {0};
char Prime::notpr[Prime::SZ + 10] = {0};

int main() {
    Prime::pr_init();
    Prime pm(113);
    Prime sb = pm.sumBit();
    Prime mb = pm.multiBit();
    Prime ssb = pm.sqaureSumBit();
    if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime()) cout << pm.getN() << " is a SuperPrime.\n";
    //test2: find all sp from 0 to 10000
    for(int i=0;i<=10000;i++){
        Prime pm(i);
        Prime sb = pm.sumBit(),mb = pm.multiBit(),ssb = pm.sqaureSumBit();
        //cout << i <<" "<< sb.getN() <<" "<< mb.getN() << " " << ssb.getN() << endl;//dbg
        if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime()){
            cout << pm.getN() << " is a SuperPrime.\n";
        }
    }
    return 0;
}
