#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h>
#define MAX 100
using namespace std;

std::ifstream input("input.txt");
std::ofstream output("output.txt");

int n,k;
int x[MAX];
int mark_cot[MAX];
int mark_cheo_chinh[MAX];
int mark_cheo_phu[MAX];
void xuat(){
    for(int i = 1;i<=n;i++){
        output<<x[i];
    }
    output<<"\n";
}
void set_mark(int i,int j,bool value){
    mark_cheo_chinh[i-j+n]=mark_cot[j]= mark_cheo_phu[i+j]=value;
}
void n_queen(int i){
    for(int j=1;j<=n;j++){
        if(mark_cot[j]==false &&
             mark_cheo_chinh[i-j+n]==false && // +n để tịnh tiến giá trị của 
            mark_cheo_phu[i+j]==false) //đường chéo chính thành số dương để lưu bằng mảng array
            {
                x[i]=j;
                set_mark(i,j,true);
                if(i==n) xuat();
                else{
                    n_queen(i+1);
                }
                set_mark(i,j,false);
             }
    }
}
void solution(){
    n_queen(1);
}

int main(){
    std::string line;
      input>>n;
      solution();
    // solution();
}