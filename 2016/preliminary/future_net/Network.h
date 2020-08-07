//
// Created by 顾俊 on 2020/8/7.
//

#ifndef _NETWORK_H
#define _NETWORK_H

#include <vector>

using namespace std;

struct Node {
    explicit Node (int id_ = -1) : id(id_) {}
    int id;
    int firstIn;        // 从该节点进来的第一条边
    int firstOut;       // 从该节点出去的第一条边
};

struct Edge {
    explicit Edge(int id_ = -1) : id(id_) {}
    int id;
    int source;
    int target;
    int weight;
    int nextIn;         // 下一个进来的边
    int nextOut;        // 下一个出去的边
};

class Network {
public:
    Network() {}
    void addNode() {
        int n = static_cast<int>(nodes.size());
        nodes.push_back(Node(n));
        nodes[n].firstIn = -1;
        nodes[n].firstOut = -1;
    }
    void addEdge(int s, int t, int w) {
        int n = static_cast<int>(edges.size());
        edges.push_back(Edge(n));
        edges[n].source = s;
        edges[n].target = t;
        edges[n].weight = w;
        edges[n].nextIn = nodes[t].firstIn;
        edges[n].nextOut = nodes[s].firstOut;
        nodes[s].firstOut = nodes[t].firstIn = n;
    }

private:
    vector<Node> nodes;
    vector<Edge> edges;
    int nodeNum;
    int edgeNum;
};


#endif //_NETWORK_H
