#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int resolver(std::string s,bool &a,int &unos) {
    int ret = 0;
    
    int casos = 0;
    if (s[s.length() - 1] == '0') {
        //ret += s[0] == '0' ? -1 : 1;
        if (s[0] == '0') ret++;
        a = false;
        casos++;
    }
    if (s[0] == '1') unos++;

    for (int i = 1; i < s.length(); i++) {
        if (s[i - 1] == '0') {
           // ret += s[i] == '0' ? -1 : 1;
            if (s[i] == '0') ret++;
            a = false;
            casos++;

        }
        if (s[i] == '1') unos++;
    }
    float probNoGirar = (float)ret / casos;
    float probGirar = (float)(s.length()-unos) / s.length();

    if (probGirar > probNoGirar) return 1;
    else if (probNoGirar > probGirar) return -1;
    return 0;
}

void resuelveCaso() {
    std::string s;
    std::cin >> s;
    bool a = true;
    int unos = 0;
    int sol = resolver(s,a,unos);

    if (sol == 1)  std::cout << "Girar\n";
    else if (sol == -1) std::cout << "No girar\n";
    else std::cout << "Da igual\n";

    //int ceros = s.length() - unos;
    //if (sol==-1*s.length()||a) std::cout << "Da igual\n";
    //else{
    //    if (sol > 0) std::cout << "Girar\n";
    //    else if (sol < 0) std::cout << "No girar\n";
    //    else {
    //        if (unos < ceros) {
    //            std::cout << "No girar\n";
    //        }
    //        else if (unos > ceros) {
    //            std::cout << "No girar\n";

    //        }else{
    //        std::cout << "Da igual\n";
    //    
    //        }
    //    }
    //}
 }

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}