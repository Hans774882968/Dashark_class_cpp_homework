/*
 * ananagrams.cxx
 * 
 * Copyright 2018 Administrator <Administrator@YJKJ-20160803PF>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

class Number {
    private:
        int num;
    public:
        Number(int num){this->num = num;}
        int getNum(){return num;}
        Number maxDivisor(Number no2){
            return gcd(num,no2.getNum());
        }
        int gcd(int a,int b){
            return b==0?a:gcd(b,a%b);
        }
        void show(){std::cout << num << std::endl;}
};

int main() {
    int n, n1, n2;
    std::cin >> n;
    for(int i = 0;i < n; ++i){
        std::cin >> n1 >> n2;
        Number no1(n1), no2(n2);
        Number no3 = no1.maxDivisor(no2); //最大公约数
        no3.show();
    }
}
