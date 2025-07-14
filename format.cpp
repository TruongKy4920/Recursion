#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h>
int n,n2; // Giá trị cho trước
using namespace std;

std::ifstream input("input.txt");
std::ofstream output("output.txt");

int Giai_thua(int i){
    if(i>1) return i*Giai_thua(i-1);
    else return 1;
}


void solution(){
    output<<Giai_thua(n);
}


int main(){
    std::string line;
    input>>n>>n2;
    solution();
}