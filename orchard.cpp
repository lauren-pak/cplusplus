#include <bits/stdc++.h>
using namespace std;

int mins = INT_MAX;
int btreesum[1000][1000] = {0};
int atreesum[1000][1000] = {0};

void getsumint(int a, int b, int c, int d, int x, int ) {
    // Calculate the number of apple trees (0) inside the rectangle
    int applesum = atreesum[c][d]
                   - (a > 0 ? atreesum[a - 1][d] : 0)
                   - (b > 0 ? atreesum[c][b - 1] : 0)
                   + (a > 0 && b > 0 ? atreesum[a - 1][b - 1] : 0);
    
    // Calculate the number of banana trees (1) inside the rectangle
    int bananasum = btreesum[c][d]
                    - (a > 0 ? btreesum[a - 1][d] : 0)
                    - (b > 0 ? btreesum[c][b - 1] : 0)
                    + (a > 0 && b > 0 ? btreesum[a - 1][b - 1] : 0);

    // Cost calculation: apples Alex loses and bananas Bert gains
    int scenario1 = applesum + (btreesum[x-1][y-1] - bananasum);
    int scenario2 = bananasum + (atreesum[x-1][y-1] - applesum);

    mins = min(mins, min(scenario1, scenario2));
}

int main(){
    int x, y; 
    cin >> x >> y;
    int bgrid[x][y];
    int agrid[x][y];
    
    // Read the orchard grid and create the complementary banana grid
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> agrid[i][j];
            bgrid[i][j] = 1 - agrid[i][j];  // Complement grid (1 - apple = banana)
        }
    }

    // Initialize the prefix sums
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            btreesum[i][j] = bgrid[i][j] + (i > 0 ? btreesum[i - 1][j] : 0) + (j > 0 ? btreesum[i][j - 1] : 0) - (i > 0 && j > 0 ? btreesum[i - 1][j - 1] : 0);
            atreesum[i][j] = agrid[i][j] + (i > 0 ? atreesum[i - 1][j] : 0) + (j > 0 ? atreesum[i][j - 1] : 0) - (i > 0 && j > 0 ? atreesum[i - 1][j - 1] : 0);
        }
    }

    // Try every rectangle and calculate the cost
    for (int a = 0; a < x; ++a) {
        for (int b = 0; b < y; ++b) {
            for (int c = a; c < x; ++c) {
                for (int d = b; d < y; ++d) {
                    getsumint(a, b, c, d);
                }
            }
        }
    }
    
    // Output the minimum fee found
    cout << mins;
}
