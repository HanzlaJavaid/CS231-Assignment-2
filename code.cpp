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
State moveleft(State input){
        int x;
        int y;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ;j++){
                if(input.S[i][j] == -1){
                    x = i ;
                    y = j;
                }
            }
        }
        if(y > 0){
            int temp = input.S[x][y-1];
            input.S[x][y-1] = input.S[x][y];
            input.S[x][y] = temp;
            return input;       
        }
        else{
            return input;
        }
    }
State moveright(State input){
        int x;
        int y;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ;j++){
                if(input.S[i][j] == -1){
                    x = i;
                    y = j;
                }
            }
        }
        if(y < 2){
            int temp = input.S[x][y+1];
            input.S[x][y+1] = input.S[x][y];
            input.S[x][y] = temp;
            return input;        
        }
        else{
            return input;
        }
    }
State moveup(State input){
        int x;
        int y;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ;j++){
                if(input.S[i][j] == -1){
                    x = i;
                    y = j;
                }
            }
        }
        if(x > 0){
            int temp = input.S[x-1][y];
            input.S[x-1][y] = input.S[x][y];
            input.S[x][y] = temp;
            return input;        
        }
        else{
            return input;
        }
    }
State movedown(State input){
        int x;
        int y;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ;j++){
                if(input.S[i][j] == -1){
                    x = i ;
                    y = j;
                }
            }
        }
        if(x < 2 ){
            int temp = input.S[x+1][y];
            input.S[x+1][y] = input.S[x][y];
            input.S[x][y] = temp;
            return input;        
        }
        else{
            return input;
        }
    }
class Graph{
    public:
        struct Vertex{
            int id;
            vector<int> edges;
            vector<State> arr;
        };
        vector<State>Visited;       
        vector<Vertex> I;
        State TargetState;
    public:
        Graph(int a, int b , int c, int d, int e ,int f, int g , int h ,  int i){
            Vertex newvertex;
            State Def;
            Def.SetState(a,b,c,d,e,f,g,h,i);
            newvertex.arr.push_back(Def);
            newvertex.id = 0;
            I.push_back(newvertex);
            Visited.push_back(Def);            
        }
        void SetTarget(int a, int b , int c, int d, int e ,int f, int g , int h ,  int i){
            TargetState.SetState(a,b,c,d,e,f,g,h,i);
        }
int main(){
	
}
