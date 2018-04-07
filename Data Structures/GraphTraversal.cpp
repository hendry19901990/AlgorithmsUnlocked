// 	Referenced from cplusplus.com
/* Debugged Version of the code here */

#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;
int studentNum;
int courseNum;
int graphSize;
int tempN, tempC;
stack <int> nodeStack;
vector <int> courseQuotas;
vector <bool> visited(2);

class Student{
public:
	int name;
	int courseCount;
	vector <int> givenCourses;
	vector <int> wantedCourses;
public:	
	Student(){
		name=0;
	}
	Student(int x, int y){
		courseCount=y;
		name=x;
	}
	void addCourses(int x){
		wantedCourses.push_back(x);
	}
};
class Edge{
public:	
	int s,t,weight, marked;
	Edge(){
		s=0;
		t=0;
		weight=1;
		marked=-1;
	}
	Edge(int x, int y){
		s=x;
		t=y;
		weight=1;
		marked=-1;
	}
	Edge(int x, int y, int z){
		s=x;
		t=y;
		weight=z;
		marked=-1;
	}
	void changeMark(){
		marked=(-1)*marked;
	}
	Edge reverse(){
		return Edge(t, s, weight);		
	}
	Edge& operator=(const Edge &v){
		if(this!=&v){
			s=v.s;
			t=v.t;
			weight=v.weight;
			marked=v.marked;
		}
		return *this;
	}
	//Destructor
	~Edge(){

	}
};


vector <Student> students;
void readFile(){
	ifstream input;
	input.open("project4.gir");
	input >> studentNum;
	input >> courseNum;
	for(int i=0; i<studentNum; i++){
		input >> tempN;
		input >> tempC;
		students.push_back(Student(i, tempC));
		for(int j=0; j<tempN; j++){
			int course;
			input >> course;
			students.at(i).addCourses(course);
		}
	}
	for(int i=0; i<courseNum; i++){
		int quota;
		input >> quota;
		courseQuotas.push_back(quota);
	}
	graphSize=2+studentNum+courseNum;
	input.close();
}
vector < vector <Edge> > graph;
void createGraph(){
	graph.resize(graphSize);
	visited.resize(graphSize);
	for(int i=0; i<graphSize; i++){
		visited.at(i)=false;
	}
	for(int i=0; i<studentNum; i++){
		graph.at(0).push_back(Edge(0, i+1, 1));
		for(int j=0; j<students.at(i).wantedCourses.size(); j++){
			graph.at(i+1).push_back(Edge(i+1, studentNum+students.at(i).wantedCourses.at(j) , 1));
		}
	}
	for(int i=0; i<courseNum; i++){
		if(courseQuotas.at(i)!=0){
			graph.at(i+1+studentNum).push_back(Edge(i+1+studentNum, 1+studentNum+courseNum , courseQuotas.at(i)));
		}
	}
}
void dfs(int vertex){
	nodeStack.push(vertex);
	visited.at(vertex)=true;
	if(vertex==graphSize) return;
		while(!nodeStack.empty()){
			int node = nodeStack.top();
			nodeStack.pop();	
			if(visited.at(graphSize-1)) break;
			for(int i=0; i<graph.at(node).size(); i++){
				if(!visited.at(graph.at(node).at(i).t)){
					nodeStack.push(graph.at(node).at(i).t);
					visited.at(graph.at(node).at(i).t)=true;
					cout << "Going from " << graph.at(node).at(i).s << " to " << graph.at(node).at(i).t << endl;				
					if(i<=studentNum){
						Edge temp = graph.at(node).at(i).reverse();
						temp.changeMark();
						graph.at(graph.at(node).at(i).t).push_back(temp);
						graph.at(node).erase(graph.at(node).begin()+i-1);
					}
					break;
				}
			}
		}
		visited.at(graphSize-1)=false;
		cout << "----------------------------" << endl;
}
void makeUnvisited(){
	vector<bool>::iterator it;
	for(it=visited.begin(); it<visited.end(); it++){
		visited.at(*it)=false;
	}
}
int main(){
	readFile();
	createGraph();
	/*
	for(int i=0; i<graph.size()-1; i++){
		cout << "The edges from node " << i << ": " << endl;;
		for(int j=0; j<graph.at(i).size(); j++){
			cout << "	Source node: "<< graph.at(i).at(j).s << endl; 
			cout << "	Target node: "<< graph.at(i).at(j).t << endl; 
			cout << "	Weight of the edge: "<< graph.at(i).at(j).weight << endl; 
			cout << "		---" << endl;
		}
		cout << "--------------------------" << endl;
	}
	*/
	for(int i=0; i<studentNum; i++){
		dfs(0);
		makeUnvisited();
	}	
return 0;
}