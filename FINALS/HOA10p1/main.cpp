#include <iostream>
#include "graph.h"

using T = unsigned;

// Test DFS
void test_DFS() {
    auto G = create_reference_graph<T>();

    std::cout << "===================== GRAPH =====================" << std::endl;
    std::cout << G << std::endl;

    std::cout << "=============== DEPTH-FIRST SEARCH ===============" << std::endl;
    std::cout << "DFS Order of vertices:" << std::endl;

    auto dfs_visit_order = depth_first_search(G, 1);

    for (auto v : dfs_visit_order)
        std::cout << v << " ";

    std::cout << "\n\n";
}

// Test BFS
void test_BFS() {
    auto G = create_reference_graph<T>();

    std::cout << "============== BREADTH-FIRST SEARCH ==============" << std::endl;
    std::cout << "BFS Order of vertices:" << std::endl;

    auto bfs_visit_order = breadth_first_search(G, 1);

    for (auto v : bfs_visit_order)
        std::cout << v << " ";

    std::cout << std::endl;
}

int main() {
    test_DFS();
    test_BFS();
    return 0;
}

