#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Cell {
    public:
        Cell(){this->content = "null";}
        Cell(string con);
        Cell(int con);
        Cell(double con);
        Cell(char con[]);
        Cell(const char con[]);
        Cell(long long con);
        ~Cell(){}
        void show();
    private:
        string content;
};

class Table {
    public:
        Table(){this->row = 2,this-> col = 2;}
        Table(int row,int col);
        ~Table(){}
        int getRow(){return row;}
        int getCol(){return col;}
        void show();
        void set(int r,int c,string con);
        void set(int r,int c,int con);
        void set(int r,int c,double con);
        void set(int r,int c,char con[]);
        void set(int r,int c,const char con[]);
        void set(int r,int c,long long con);
        int addRow();
        void delRow(int n);
        int addColumn();
        void delColumn(int n);
    private:
        int row,col;
        Cell cells[256][1024];
};
//Note that using template is not appropriate here.
Cell::Cell(string con){this->content = con;}
Cell::Cell(int con){this->content = to_string(con);}
Cell::Cell(double con){this->content = to_string(con);}
Cell::Cell(char con[]){this->content = con;}
Cell::Cell(const char con[]){this->content = con;}
Cell::Cell(long long con){this->content = to_string(con);}

void Cell::show(){cout << content;}

Table::Table(int row,int col){
    this->row = row,this->col = col;
}

void Table::show(){
    for(int i=0;i<row;cout << endl,i++){
        for(int j=0;j<col;j++){
            cells[i][j].show();
            if(j < col-1) cout << " ";
        }
    }
    cout << endl;
}
//Note that using template is not appropriate here.
void Table::set(int r,int c,string con){cells[r][c] = Cell(con);}
void Table::set(int r,int c,int con){cells[r][c] = Cell(con);}
void Table::set(int r,int c,double con){cells[r][c] = Cell(con);}
void Table::set(int r,int c,char con[]){cells[r][c] = Cell(con);}
void Table::set(int r,int c,const char con[]){cells[r][c] = Cell(con);}
void Table::set(int r,int c,long long con){cells[r][c] = Cell(con);}
int Table::addRow(){
    row++;
    return row;
}

void Table::delRow(int n){
    for(int i=n;i<row-1;i++){
        for(int j=0;j<col;j++){
            cells[i][j] = cells[i+1][j];
        }
    }
    row--;
}

int Table::addColumn(){
    col++;
    return col;
}

void Table::delColumn(int n){
    for(int j=n;j<col-1;j++){
        for(int i=0;i<row;i++){
            cells[i][j] = cells[i][j+1];
        }
    }
    col--;
}
Table tb,tb1(5,5),tb2(6,6);
int main() {
    tb.show();
    tb.addRow();
    tb.show();
    tb.addColumn();
    tb.show();
    tb1.show();
    tb1.set(1,1,30);
    tb1.set(2,2,"hello");
    tb1.show();
    tb1.delRow(1);
    tb1.show();
    tb1.delColumn(1);
    tb1.show();
    for(int i=0;i<6*6;i++) tb2.set(i/6,i%6,i);
    tb2.show();
    tb2.addRow();tb2.show();
    tb2.addColumn();tb2.show();
    tb2.delRow(1);tb2.show();
    tb2.delColumn(0);tb2.show();
    tb2.addRow();for(int j=0;j<tb2.getCol();j++){tb2.set(tb2.getRow()-1,j,"world");}tb2.show();
    tb2.addColumn();for(int i=0;i<tb2.getRow();i++){tb2.set(i,tb2.getCol()-1,1.1);}tb2.show();
    tb2.delRow(2);tb2.show();
    tb2.delColumn(2);tb2.show();
    return 0;
}
