// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.


#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create an adjacency list to represent the flights
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            graph[from].emplace_back(to, price);
        }

        // Min heap to store {cost, city, stops} for Dijkstra's algorithm
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // Initial push to the priority queue
        pq.push({0, src, 0});

        while (!pq.empty()) {
            vector<int> cur = pq.top();
            pq.pop();

            int curCost = cur[0];
            int curCity = cur[1];
            int curStops = cur[2];

            // If the destination is reached, return the cost
            if (curCity == dst) {
                return curCost;
            }

            // If the number of stops is within the allowed limit
            if (curStops <= k) {
                // Explore neighbors
                for (const auto& neighbor : graph[curCity]) {
                    int nextCity = neighbor.first;
                    int nextCost = neighbor.second;

                    // Add the neighbor to the priority queue
                    pq.push({curCost + nextCost, nextCity, curStops + 1});
                }
            }
        }

        // If no valid route is found
        return -1;
    }
};

