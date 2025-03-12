#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

struct graph {
    using T = int;
    
public:
    void addEdge(int u, int v, T weight) {
        adjacencyList[u].push_back(std::make_pair(v, weight));
        adjacencyList[v].push_back(std::make_pair(u, weight));
    }

    graph(int bigSize) {
        maxSize = bigSize; 
        adjacencyList.resize(maxSize);
        visited.resize(maxSize);
    }

    /* Assumes graph is already connected.. */
    std::pair<std::vector<std::tuple<int, int, T>>, T> calculateMinimumSpanningTree() {
        // we know zero exists within the array
        // start at zero
        //
        T totalCost = 0;
        std::vector<std::tuple<int, int, T>> edges;

        pq.push(std::make_pair(0, 0));

        std::function<void()> dfs = [&]() {
            auto u = pq.top();
            pq.pop();

            if(visited[u.second]) {
                return;
            }

            visited[u.second]=true;

            sort(adjacencyList[u.second].begin(), adjacencyList[u.second].end(), [](auto a, auto b) {
                return a.second < b.second;
            });

            for(const auto &otherNode : adjacencyList[u.second]) {
                if(!visited[otherNode.first]) {
                    pq.push({otherNode.second, otherNode.first});
                    totalCost += otherNode.second;
                    edges.push_back(std::make_tuple(otherNode.first, u.second, otherNode.second));
                    dfs();
                }
            }

        };

        dfs();
        return {edges, totalCost};
    }


private:
    int maxSize;
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;
    std::vector<bool> visited;
    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> pq;



};


