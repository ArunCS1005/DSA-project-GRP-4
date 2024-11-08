#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <unordered_map>

using namespace std;

const int NUM_ITERATIONS = 10000;
const double DAMPING_FACTOR = 0.85;

class GraphNode {
public:
    string name;
    vector<int> neighbors;

    GraphNode(const string& nodeName) : name(nodeName) {}
};

void initializeGraph(vector<GraphNode>& graph) {
    int numNodes;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    graph.reserve(numNodes);

    cout << "Enter the names of the nodes:\n";
    for (int i = 0; i < numNodes; ++i) {
        string nodeName;
        cin >> nodeName;
        graph.emplace_back(nodeName);
    }

    cout << "Enter the neighbors for each node (enter -1 to stop):\n";
    for (int i = 0; i < numNodes; ++i) {
        cout << "Neighbors of " << graph[i].name << ": ";
        while (true) {
            int neighbor;
            cin >> neighbor;
            if (neighbor == -1) break;
            if (neighbor >= 0 && neighbor < numNodes) {
                graph[i].neighbors.push_back(neighbor);
            } else {
                cout << "Invalid neighbor index. Try again: ";
            }
        }
    }
}

void printGraph(const vector<GraphNode>& graph) {
    for (const auto& node : graph) {
        cout << node.name << ": ";
        for (int neighbor : node.neighbors) {
            cout << graph[neighbor].name << " ";
        }
        cout << endl;
    }
}

void pageRank(const vector<GraphNode>& graph, vector<double>& ranks) {
    vector<int> visitCount(graph.size(), 0);
    int currentNode = rand() % graph.size();

    for (int iter = 0; iter < NUM_ITERATIONS; ++iter) {
        visitCount[currentNode]++;
        double randomValue = (double)rand() / RAND_MAX;

        if (randomValue < DAMPING_FACTOR) {
            if (!graph[currentNode].neighbors.empty()) {
                currentNode = graph[currentNode].neighbors[rand() % graph[currentNode].neighbors.size()];
            } else {
                currentNode = rand() % graph.size();
            }
        } else {
            currentNode = rand() % graph.size();
        }
    }

    for (int i = 0; i < graph.size(); ++i) {
        ranks[i] = (double)visitCount[i] / NUM_ITERATIONS;
    }
}

int main() {
    vector<GraphNode> graph;
    vector<double> ranks;

    initializeGraph(graph);
    ranks.resize(graph.size(), 0.0);

    cout << "Graph:\n";
    printGraph(graph);

    pageRank(graph, ranks);

    cout << "\nPage Ranks after " << NUM_ITERATIONS << " iterations:\n";
    for (int i = 0; i < ranks.size(); ++i) {
        cout << graph[i].name << ": " << fixed << setprecision(4) << ranks[i] << endl;
    }

    return 0;
}