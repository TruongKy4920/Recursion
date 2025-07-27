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

int n,m;
int x[MAX];
void xuat(int xet,int koxet,bool upper_first){
    bool have_open=false; //mac dinh cac cong tac dang dong
    for(int i=1;i<= xet;i++){
        if(x[i]=='O') have_open=true;
    }
    if(!have_open) return;

    if(upper_first){
        for(int i=1;i<=xet;i++) output<<char(x[i])<<" ";
        for(int i=1;i<=koxet;i++) output<<"C ";
    }
    else {
        for(int i=1;i<=koxet;i++) output<<char(x[i])<<" ";
        for(int i=1;i<=xet;i++) output<<"C ";
    }
    output<<"\n";
 }
    

void cong_tac(int i,int xet, int koxet,bool upper_first){
    for(int v:{'C','O'}){
        if(true){
            if(i==xet) xuat(xet,koxet,upper_first);
            else cong_tac(i+1,xet,koxet,upper_first);
        }
    }
}


void solution(){
    cong_tac(1,n,m,true);
    cong_tac(1,m,n,false);
}

int main(){
    std::string line;
      input>>n>>m;
      for(int i=1;i<=m+n;i++){
        output<<"C ";
      }
      output<<"\n";
      solution();
    // solution();
}