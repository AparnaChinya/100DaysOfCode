#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
bool flag[21] = {0,0};


int maximum = 20;
void crossOff(int prime) {
    for(int i = prime*prime; i < maximum; i=i+prime) {
        flag[i] = false;
    }
}
int getNextPrime(int prime) {
    int next = prime + 1;
    while(!flag[next] && next < maximum) {
        next++;
    }

    return next;
}

int main() {
	int prime = 2;
	 for(int i = 2; i < maximum; i++) {
        flag[i] = true;
    }
	while(prime <= sqrt(maximum)) {

	    crossOff(prime);
	    prime = getNextPrime(prime);

	}

    for(int i = 0; i < maximum; i++) {
        cout << i << " " << flag[i] <<endl;
    }


	return 0;
}