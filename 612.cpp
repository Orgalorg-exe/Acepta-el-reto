#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

struct t_punto {
    int x;
    int y;
};

double dist(t_punto a, t_punto b) {
    long long x = pow(a.x - b.x, 2);
    long long y = pow(a.y - b.y, 2);
    return sqrt(x + y);
}

int resolver(long long R, t_punto const & p) {

    long long ret = 0;
    t_punto c = {0, 0};
    double d;
    bool xGEy, xIsPos, yIsPos;

    while (R) {
        d = dist(p, c);

        if (d <= R) ret++;


        if ((p.y - c.y > p.x - c.x ) &&
            (p.y - c.y > -p.x + c.x)) 
        {
            c.y += R;
        }
        else if ((p.y - c.y < p.x - c.x) &&
                 (p.y - c.y < -p.x + c.x)) 
        {
            c.y -= R;
        }
        else if ((p.y - c.y < p.x - c.x) &&
                 (p.y - c.y > -p.x + c.x))
        {
            c.x += R;
        }
        else {
            c.x -= R;
        }

        R /= 2;
    } 

    return ret;
}

bool resuelveCaso() {
    int R;
    std::cin >> R;

    if (! std::cin)
        return false;
    
    t_punto p;
    std::cin >> p.x >> p.y;

    int sol = resolver(R, p);
    
    std::cout << sol << '\n';
    
    
    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}