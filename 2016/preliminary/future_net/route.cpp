//
// Created by 顾俊 on 2020/8/7.
//

#include "route.h"
#include <iostream>
#include <vector>

using namespace std;

int MAX_NODE_INDEX = INT_MIN; // 最大节点序号

struct Info {
    int i;
    int s;
    int t;
    int w;
    Info(int a, int b, int c, int d) : i(a), s(b), t(c), w(d) {}
};
vector<Info> infos;

/**
 *
 * @param graph 图拓扑信息字符串数组
 * @param edge_num 边条数
 * @param condition 起始，终点，必经节点信息
 */
void search_route(char *graph[5000], int edge_num, char *condition)
{
    cout << "topo: " << endl;
    int a, b, c, d;
    for (int i = 0; i < edge_num; ++i) {
        cout << graph[i];
        sscanf(graph[i], "%d,%d,%d,%d\n", &a, &b, &c, &d);
        MAX_NODE_INDEX = max(MAX_NODE_INDEX, b);
        MAX_NODE_INDEX = max(MAX_NODE_INDEX, c);
        infos.emplace_back(a,b,c,d);
    }

    cout << endl;

    cout << "demand: " << endl;
    cout << condition << endl;
}
