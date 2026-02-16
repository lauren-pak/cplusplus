#include <bits/stdc++.h>
#include <cmath>

using namespace std;

long long supply(int P);
long long demand(int P);

int getPrice(int P) {
    int startp = 0, endp = P; // Initialize startp and endp to the range [0, P]

    while (startp < endp) { // Modify the loop condition
        int mid = startp + (endp - startp) / 2; // Calculate the midpoint

        // Calculate the quantity supplied and demanded at the midpoint
        long long supplied = supply(mid);
        long long demanded = demand(mid);

        if (supplied < demanded) {
            startp = mid + 1; // Adjust startp if supplied < demanded
        } else {
            endp = mid; // Adjust endp if supplied >= demanded
        }
    }

    // Return the equilibrium price
    return startp;
}
