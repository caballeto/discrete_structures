/*
 * main.cpp
 *  Exercise 10 from discrete structure lab 3
 *  Created on: Apr 18, 2018
 *      Author: napoleon
 */

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

// graph node
struct node {
	int num = 0;
	int M_num = -1; // M enumeration starts from 0
	bool checked = false;
	vector<int> near;
};

// function prototypes
bool check(vector<int> array, int value);
vector<node*> random_graph();
void M_numeration(vector<node*> &);
void DFS(int i, vector<node*> &graph);
int get_current_num(vector<node*>);
void display_m_numeration(vector<node*>);
void display_table(vector<node*> graph);

int main() {
	// initialize random graph of size 5
	vector<node*> graph = random_graph();
	M_numeration(graph);
	display_table(graph);
	display_m_numeration(graph);
	return 0;
}

void M_numeration(vector<node*> &graph) {
	for(unsigned int i = 0; i < graph.size(); i++) {
		if(!graph[i]->checked) {
			DFS(i, graph);
		}
	}
}

void DFS(int k, vector<node*> &graph) {
	graph[k]->checked = true;
	graph[k]->M_num = get_current_num(graph) + 1;// -1 + 1 = 0 -> numeration from 0
	for(unsigned int i = 0; i < graph[k]->near.size(); i++) {
		if(!graph[graph[k]->near[i]]->checked) {
			DFS(graph[k]->near[i], graph);
		}
	}
}

vector<node*> random_graph() {
	vector<node*> graph;
	int N = 5; // number of tops in graph
	for(int i = 0; i < N; i++) {
		node* temp = new node;
		graph.push_back(temp);
	}

	for(int i = 0;i < N; i++) {
		graph[i]->num = i;
		int k = rand()%(N-1) + 1;
		for(int j = 0; j < k; j++) {
			int randomized = rand()%(N-1)+1;
			if(!check(graph[i]->near, randomized) && randomized != i) {
				graph[i]->near.push_back(randomized);
				graph[randomized]->near.push_back(i);
			}
		}
	}
	return graph;
}

bool check(vector<int> array, int value) {
	for(unsigned int i = 0; i < array.size(); i++) {
		if(array[i] == value)
			return true;
	}
	return false;
}

int get_current_num(vector<node*> graph) {
	int current_num = graph[0]->M_num;
	for(unsigned int i = 0;i < graph.size(); i++) {
		if(graph[i]->M_num >= current_num) {
			current_num = graph[i]->M_num;
		}
	}
	return current_num;
}

void display_table(vector<node*> graph) {
	cout << "Displaying graph table:" << endl;
	for(unsigned int i = 0; i < graph.size(); i++) {
		cout << graph[i]->num << ": ";
		for(unsigned int k = 0; k < graph[i]->near.size(); k++) {
			cout << graph[i]->near[k] << " ";
		}
		cout << endl;
	}
}

void display_m_numeration(vector<node*> graph) {
	cout << "Displaying M numeration:" << endl;
	for(unsigned int i = 0; i < graph.size(); i++) {
		cout << graph[i]->num << ": " << graph[i]->M_num << endl;
	}
}

