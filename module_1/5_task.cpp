#include <iostream>
#include <list>
#include <cmath>
#include <climits>
using namespace std;
using iter = list<int>::iterator;

int main() {
    int k;
    cin >>k;
    list<int> l(k);
    iter buf = l.begin();
    int max = INT_MAX;

    for(iter iterator = l.begin(); iterator != l.end(); iterator++) {
        cin >> *iterator;
    }

    for(iter i= l.begin(); i != l.end(); i++) {
        if (abs(*i - *next(i,1)) < max) {
            max = abs(*i - *next(i,1)); 
            buf = i;
        }
    }

    cout << *buf <<' '<< *next(buf, 1) <<'\n';

    return 0;
}