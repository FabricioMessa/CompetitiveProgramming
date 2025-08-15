#include <iostream>
#include <string>
using namespace std;

int calcularTiempo(const string& S){
    if(S.size() == 0){
        return 0;
    }
    int tiempo = 2;
    for(int i=0; i<S.size(); ++i){
        if(S[i] == S[i+1]){
            tiempo +=1;
        } else {
            tiempo +=2;
        }
    }
    return tiempo;
}

int main(){
    string S;
    cin >> S;
    int max_tiempo = -1;
    string nuevo = "";
    for(int i=0; i<S.size();++i){
        for(char c = 'a'; c <= 'z'; ++c){
            nuevo.insert(i, 1, c);
            int actu = calcularTiempo(nuevo);

            if(actu > max_tiempo){
                max_tiempo = actu;
                
            }   

        }
    }

    return 0;
}