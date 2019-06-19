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

class DotArray {   //点阵对象
private:
    int num;
public:
    DotArray(){}
    DotArray(int num){this->num = num;}
    static const int maxcol = 7, maxrow = 7;
    static const char da[7][70+1];
    int getNum(){return num;}
    //virtual void showrow() const;
};
class DAPrinter {
private:
    const int num;
    int sz;
    DotArray das[4]; //最多4个点阵对象
public:
    DAPrinter(int n1):num(n1){sz = 0;}
    void split();
    void print();
    void reset();
};
const char DotArray::da[7][70+1] = {
    "*****      *  *****  *****  *   *  *****  *****  *****  *****  *****  ",
    "*   *      *      *      *  *   *  *      *          *  *   *  *   *  ",
    "*   *      *      *      *  *   *  *      *          *  *   *  *   *  ",
    "*   *      *  *****  *****  *****  *****  *****      *  *****  *****  ",
    "*   *      *  *          *      *      *  *   *      *  *   *      *  ",
    "*   *      *  *          *      *      *  *   *      *  *   *      *  ",
    "*****      *  *****  *****      *  *****  *****      *  *****  *****  "
};
int main() {
    int n;
    std::cin >> n;
    for(int i = 0,n1; i < n; ++i) {
        std::cin >> n1;
        DAPrinter p(n1);
        p.split();
        p.print();
    }
    return 0;
}

void DAPrinter::split(){
    for(int n1 = num;n1 > 0;n1 /= 10){
        das[sz++] = DotArray(n1 % 10);
    }
}

void DAPrinter::print(){
    std::cout << num << ":" << std::endl;
    for(int i=0;i<DotArray::maxrow;i++){
        for(int sz1 = sz;sz1 > 0;sz1--){
            for(int cnt=0,j=das[sz1-1].getNum()*7;cnt<DotArray::maxcol;cnt++,j++){
                std::cout << DotArray::da[i][j];
            }
        }
        std::cout << std::endl;
    }
}

void DAPrinter::reset(){sz = 0;}
