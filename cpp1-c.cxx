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

class Number {
    private:
        char digs[1000010];
        int num,cnt,typ;
    public:
        Number(int num,int typ){
            this->num = num;this->typ = typ;
            cnt = 0;
        }
        int toInt(){
            int ret = 0;
            for(int i=cnt-1;i>=0;i--) ret = 10 * ret + (digs[i]-'0');
            return ret;
        }
        int getTyp(){return typ;}
        Number converto(int b){
            for(int num1 = num;num1;num1 /= b){
                digs[cnt++] = (num1 % b < 10)?(num1 % b + '0'):(num1 % b - 10 + 'A');
            }
            Number ret(toInt(),b);
            return ret;
        }
        void show(){
            std::cout << num << std::endl;
        }
};

int main() {
    int n, n1, n2;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> n1 >> n2;
        Number no1(n1,10); //n1是10进制正整数
        Number no3 = no1.converto(n2); //no3是n2进制的正整数
        no3.show();
    }
}
