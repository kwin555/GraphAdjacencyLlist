#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdlib>
#include <vector>
void reverseStack(std::stack<int> &input) {
    std::stack<int> tempStack;
    while(!input.empty()) {
        int temp = input.top();
        input.pop();
        tempStack.push(temp);
    }
    input = tempStack;

}
struct node{
    int data;
    node *left;
    node *right;
    int height;
};

class graph {
private:
    bool** adjMatrix;
    int size;
    void dfsUtil(int source);
public:
    graph(int);
    void print();
    void randomlyAssign();
    void bfs(int source);
    void dfs(int source);
};

// graph::~graph() {
//     for (int i = 0; i < size; i++)
//         delete[] adjMatrix[i];
//     delete[] adjMatrix;
// }
void graph::bfs(int source) {
    std::queue<int> intQueue;
    bool *visited = new bool [size];
    for (int i = 0; i < size; i++) {
        visited[i] = false;
    }

    intQueue.push(source);
    while(!intQueue.empty()) {
        source = intQueue.front();
        intQueue.pop();
        if (!visited[source]) {
            std::cout << source << " ";
            visited[source] = true;
        }
        for (int i = 0; i < size; i++) {
            if (!visited[i] && adjMatrix[source][i] == 1) {
                intQueue.push(i);
            }
        }
    }
}
 void graph::dfs(int source) {
     std::stack<int> intStack;
     bool *visited = new bool [size];
     for (int i = 0; i < size; i++) {
         visited[i] = false;
     }
     int counter = 0;
     intStack.push(source);
     while(!intStack.empty()) {
         source = intStack.top();
         intStack.pop();
         if (!visited[source]) {
             std::cout << source << " ";
             visited[source] = true;
         }
         for (int i = 0; i < size; i++) {
             if (!visited[i] && adjMatrix[source][i] == 1) {
                 intStack.push(i);
             }
         }
        reverseStack(intStack);
     }
 }
graph::graph(int graphsize) {
    this->size = graphsize;
    adjMatrix = new bool*[size];
    for (int i = 0; i < size; i++) {
        adjMatrix[i] = new bool[size];
        for(int j = 0; j < size; j++) {
            adjMatrix[i][j] = false;
        }
    }
}

void graph::randomlyAssign() {
    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if (i != j ) {
                int oneOrZero = rand() % 2;
                adjMatrix[i][j] = oneOrZero;
            }

        }
    }
}

void graph::print() {
    std::cout << "   ";
    for (int k = 0; k < size; k++)
        std::cout << " " << k;
    std::cout << "\n";
    std::cout << "------------------------\n";
    for (int i = 0; i < size; i++) {
        std::cout << i << " : ";
        for(int j = 0; j < size; j++) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}


int main () {
    int graphsize = 0;
    std::cout << "enter the size of the graph:\n";
    std::cin >> graphsize;
    graph intGraph(graphsize);
    intGraph.randomlyAssign();
    intGraph.print();
    intGraph.dfs(0);
    return 0;
}
