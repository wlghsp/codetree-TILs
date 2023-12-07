#include <iostream>
#include <string>
#include <climits>
using namespace std;

int n;
string seats;

void Input() {
    cin >> n >> seats;
}


int main() {
    Input();

    int max_dist = 0;
    int max_i, max_j;
    for(int i = 0; i < n; i++) {
        if (seats[i] == '1') {
            for(int j = i + 1; j < n; j++) {
                if(seats[j] == '1') {
                    if (j - i > max_dist) {
                        max_dist = j - i;

                        max_i = i;
                        max_j = j;
                    }
                    break;
                }
                
            }
        }
    }

    seats[(max_i + max_j) / 2] = '1';

    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        if (seats[i] == '1') {
            for(int j = i + 1; j < n; j++) {
                if (seats[j] == '1') {
                    ans = min(ans, j - i);
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}