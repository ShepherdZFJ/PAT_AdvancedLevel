#include <iostream>
using namespace std;
 
int main() {
    int a1, a2, b1, b2, c1, c2;
    int a = 0, b = 0, c = 0, m;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
    c = c1 + c2;
    if(c >= 29) {
        m = c;
        c = m % 29;
        b = b + m/29;
    }
    b += (b1 + b2);
    if(b >= 17) {
        m = b;
        b = m % 17;
        a = a + m / 17;
    }
    a += (a1 + a2);
    printf("%d.%d.%d\n", a, b, c);
    return 0;
}