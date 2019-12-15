#include<iostream>
#include<vector>
#include<fstream>
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
        void AddEdge(int source , int target){
            for(int i = 0 ; i < I.size() ; i++){
                if(I[i].id == source){
                    I[i].edges.push_back(target);
                }
            }
        }
        bool IsAlreadyVisited(State input){
            bool IsVisited = false;
            for(int i = 0 ; i < Visited.size(); i++){
                if(IsTarget(input,Visited.at(i))){
                    IsVisited = true;
                    return IsVisited;
                }
            }
            return IsVisited;
        }
        bool IsTarget(State a , State b){
            bool IsTarget = true;
            for(int i = 0 ; i< 3; i++){
                for(int j = 0 ; j < 3 ;j++){
                    if(a.S[i][j]!=b.S[i][j]){
                        IsTarget = false;
                    }
                }
            }
            return IsTarget;
        }
        void FindPath(Vertex currentState , bool ToShow){
            int count = 0;
            while(!IsTarget(currentState.arr.at(0),TargetState)){
                count++;
                State TempState[4];
                TempState[0] = moveleft(currentState.arr.at(0));
                TempState[1] = moveright(currentState.arr.at(0));
                TempState[2] = moveup(currentState.arr.at(0));
                TempState[3] = movedown(currentState.arr.at(0));
                for(int i = 0 ; i < 4 ; i++){
                    if(IsTarget(TempState[i],TargetState)){
                        Visited.push_back(TempState[i]);
                        Vertex newvertex = AddVertex(TempState[i]);
                        AddEdge(currentState.id,newvertex.id);
                        return;
                    }
                }
                for(int i = 0 ; i < 4 ; i ++){
                    bool IsVisited = false;
                    IsVisited = IsAlreadyVisited(TempState[i]);
                    if(IsVisited == false){
                        Visited.push_back(TempState[i]);
                        if(ToShow == true){
						TempState[i].show();
                        cout << endl;
                    }
                        Vertex newvertex = AddVertex(TempState[i]);
                        AddEdge(currentState.id,newvertex.id);
                    }
                }
                currentState = I[count];
            }
			cout << "Last appearing state is GOAL state ....." << endl;
        }      
        void AddVertex(int a, int b , int c, int d, int e ,int f, int g , int h ,  int i){
            Vertex newvertex;
            State newState;
            newState.SetState(a,b,c,d,e,f,g,h,i);
			newvertex.arr.push_back(newState);
            newvertex.id = I.size();
            I.push_back(newvertex);
        }
        Vertex AddVertex(State input){
            Vertex newvertex;
            State newState = input;
            newvertex.arr.push_back(newState);
            newvertex.id = I.size();
            I.push_back(newvertex);
            return newvertex;
        }
        void print(){
            for(int i = 0 ; i < I.size();i++){
                I[i].arr.at(0).show() ;
                if(I[i].edges.size()==0){
                	cout << "This Vertex(State) is connected to no other vertex . This may take some time ." << endl;
				}
				else{
					cout << "is connected with " << endl ;
				}
                for(int j = 0 ; j < I[i].edges.size();j++){
                I[I[i].edges.at(j)].arr.at(0).show(); 
                }
                cout << endl ;
                cout << "--------------";
                cout << endl;
                cout << endl;
                cout << endl;
            }
        }
        

};
int main(){
ifstream reader("input_start.txt");
int arr[9];
for(int i = 0 ; i < 9 ;i++){
    arr[i] = 0;
}
int index = 0;
cout << "START STATE : " << endl;
while(reader >> arr[index]){
	if(index%3 == 0&& index !=0 ){
		{
		cout << endl;}
	}
	cout << arr[index] << " ";
	index++;}
cout << endl;
index = 0;
Graph X(arr[0],arr[1],arr[2],
        arr[3],arr[4],arr[5],
        arr[6],arr[7],arr[8]
        );
ifstream reader2("input_target.txt");
cout << endl;
cout << "GOAL STATE : " << endl;
while(reader2 >> arr[index]){
	if(index%3 == 0&& index !=0 ){
		{
		cout << endl;}
	}
	cout << arr[index] << " ";
	index++;}
cout << endl << endl ;
cout << "Now Graph will appear that goes to Goal state . It will show all possibilities with connections .."<< endl;
reader.close();
reader2.close();
bool ToShow = false;
int input ;
cout << "If you want to see every intermediate state during the time of creation the Enter 1 "<<endl<< "OR" << endl <<"if you want to see the end result graph then Enter 2 " << endl;
cin >> input;
switch(input){
	case 1:
		ToShow = true;
		break;
	case 2:
		ToShow = false;
		break;
	default:
		cout << "Enter valid input" << endl;
		break;
}
X.SetTarget(arr[0],arr[1],arr[2],
        arr[3],arr[4],arr[5],
        arr[6],arr[7],arr[8]
        );
X.FindPath(X.I[0],ToShow);
X.print();
}
