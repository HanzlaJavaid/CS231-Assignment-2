///Hanzla Javaid 2018271 
///Assignment#2
#include<iostream>
using namespace std;
class State{
    public:
    int S[3][3];
    public:
    State(){
    }
    void SetState(int a, int b , int c, int d, int e ,int f, int g , int h ,  int i){
        S[0][0] = a;
        S[0][1] = b;
        S[0][2] = c;
        S[1][0] = d;
        S[1][1] = e;
        S[1][2] = f;
        S[2][0] = g;
        S[2][1] = h;
        S[2][2] = i;
    }
    void show(){
        for(int i = 0 ; i < 3; i++){
            for(int j =0 ; j < 3; j++){
                cout << S[i][j] << "  " ;
            }
            cout << endl;
        }
    }
};
int main(){
	
}
