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
class HanXin {
    private:
        int n1,n2,n3;
    public:
        HanXin(){}
        void line3(int n1){
            this->n1 = n1;
        }
        void line5(int n2){
            this->n2 = n2;
        }
        void line7(int n3){
            this->n3 = n3;
        }
        void showMany(){
            for(int i = 10;i <= 100;i++){
                if(i % 3 == n1 && i % 5 == n2 && i % 7 == n3){
                    std::cout << i << std::endl;
                    return;
                }
            }
            std::cout << "Impossible\n";
        }
};

int main() {
    int n, n1, n2, n3;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        std::cin >> n1 >> n2 >> n3;
        HanXin hx; //韩信
        hx.line3(n1); //3人一排
        hx.line5(n2); //5人一排
        hx.line7(n3); //7人一排
        hx.showMany();
    }
}
