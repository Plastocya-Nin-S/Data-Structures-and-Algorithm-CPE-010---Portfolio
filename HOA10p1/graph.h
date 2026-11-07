#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>

template <typename T>
class Graph;

template <typename T>
struct Edge {
    size_t src, dest;
    T weight;

    inline bool operator<(const Edge<T> &e) const {
        return weight < e.weight;
    }

    inline bool operator>(const Edge<T> &e) const {
        return weight > e.weight;
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Graph<T> &G) {
    for (size_t i = 1; i <= G.vertices(); i++) {
        os << i << ":\t";
        for (const auto &e : G.outgoing_edges(i))
            os << "{" << e.dest << ": " << e.weight << "}, ";
        os << std::endl;
    }
    return os;
}

template <typename T>
class Graph {
public:
    Graph(size_t N) : V(N) {}

    size_t vertices() const {
        return V;
    }

    const std::vector<Edge<T>> &edges() const {
        return edge_list;
    }

    void add_edge(Edge<T> &&e) {
        if (e.src >= 1 && e.src <= V &&
            e.dest >= 1 && e.dest <= V)
            edge_list.emplace_back(e);
        else
            std::cerr << "Vertex out of bounds" << std::endl;
    }

    std::vector<Edge<T>> outgoing_edges(size_t v) const {
        std::vector<Edge<T>> result;
        for (const auto &e : edge_list)
            if (e.src == v)
                result.emplace_back(e);
        return result;
    }

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os,
                                    const Graph<U> &G);

private:
    size_t V;
    std::vector<Edge<T>> edge_list;
};

// Create the graph from the activity
template <typename T>
Graph<T> create_reference_graph() {
    Graph<T> G(9);
    std::map<unsigned, std::vector<std::pair<size_t, T>>> edges;

    edges[1] = {{2, 2}, {5, 3}};
    edges[2] = {{1, 2}, {5, 5}, {4, 1}};
    edges[3] = {{4, 2}, {7, 3}};
    edges[4] = {{2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5}};
    edges[5] = {{1, 3}, {2, 5}, {4, 2}, {8, 3}};
    edges[6] = {{4, 4}, {7, 4}, {8, 1}};
    edges[7] = {{3, 3}, {6, 4}};
    edges[8] = {{4, 5}, {5, 3}, {6, 1}};

    for (const auto &i : edges)
        for (const auto &j : i.second)
            G.add_edge(Edge<T>{i.first, j.first, j.second});

    return G;
}

// Depth-First Search
template <typename T>
std::vector<size_t> depth_first_search(const Graph<T> &G, size_t dest) {
    std::stack<size_t> stack;
    std::vector<size_t> visit_order;
    std::set<size_t> visited;

    stack.push(1);

    while (!stack.empty()) {
        size_t current = stack.top();
        stack.pop();

        if (visited.find(current) == visited.end()) {
            visited.insert(current);
            visit_order.push_back(current);

            for (const auto &e : G.outgoing_edges(current))
                if (visited.find(e.dest) == visited.end())
                    stack.push(e.dest);
        }
    }
    return visit_order;
}

// Breadth-First Search
template <typename T>
std::vector<size_t> breadth_first_search(const Graph<T> &G, size_t dest) {
    std::queue<size_t> queue;
    std::vector<size_t> visit_order;
    std::set<size_t> visited;

    queue.push(1);

    while (!queue.empty()) {
        size_t current = queue.front();
        queue.pop();

        if (visited.find(current) == visited.end()) {
            visited.insert(current);
            visit_order.push_back(current);

            for (const auto &e : G.outgoing_edges(current))
                if (visited.find(e.dest) == visited.end())
                    queue.push(e.dest);
        }
    }
    return visit_order;
}

#endif


