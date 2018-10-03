/*

A palindromic number reads the same both ways.
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>

#include<vector>

using namespace std;

bool checkIfLargest(int N){
    int Nc = N;
    int factor = 2;

    vector<int> factors;

    while( N > 1){
        if(N % factor == 0){
            N = N / factor;
            factors.push_back(factor);
            while(N % factor == 0){
                factors.push_back(factor);
                N = N / factor;
            }
        }
        factor = factor+1;
    }

    int a = 1;
    int b = 1;

    while(factors.size()>0){
        int factor = factors.back();
        if(a<=b && a*factor<1000){
            a *= factor;
        }else if(b*factor<1000){
            b *= factor;
        }else{
            cout<<factor << " - " << a << " " << b << " " << Nc <<endl;
            return false;
        }
        factors.pop_back();
    }

    return true;
}

bool checkIfValidPalindrome(string a){
    int d = a.length();
    return (a[0] == a[d-1]) && (a[1] == a[d-2]) && (a[2] == a[d-3]) ;
}

int main(void){
    const int MAX = 999999;

    int i;
    for(i = MAX;i>10000; i--){
        stringstream ss;
        ss << i;
        string s = ss.str();

        if( checkIfValidPalindrome(s) && checkIfLargest(i) ){
            break;
        }
    }

    cout << i;

    return 0;
}
