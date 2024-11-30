#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Structure to represent a road project
struct Road {
    string identifier;
    int priority;
    int cost;
    string area1, area2;
};

// Comparator for sorting based on priority and cost
bool compareRoads(const Road &a, const Road &b) {
    if (a.priority != b.priority) 
        return a.priority > b.priority; // Higher priority comes first
    return a.cost > b.cost; // Higher cost comes first if priority is the same
}

class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unionSets(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return false; // Already connected
        if (rank[rootX] > rank[rootY]) 
            parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY]) 
            parent[rootX] = rootY;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

int main() {
    int n;
    cin >> n; // Number of road projects
    vector<Road> roads(n);
    unordered_map<string, int> areaMap; // Map area names to unique indices
    int areaCount = 0;

    for (int i = 0; i < n; ++i) {
        cin >> roads[i].identifier >> roads[i].priority >> roads[i].cost >> roads[i].area1 >> roads[i].area2;
        if (areaMap.find(roads[i].area1) == areaMap.end()) areaMap[roads[i].area1] = ++areaCount;
        if (areaMap.find(roads[i].area2) == areaMap.end()) areaMap[roads[i].area2] = ++areaCount;
    }

    // Sort the roads based on priority and cost
    sort(roads.begin(), roads.end(), compareRoads);

    // Output the sorted list of road projects
    cout << "\nSorted List of Projects:" << endl;
    for (const Road &road : roads) {
        cout << road.identifier << " " << road.priority << " " << road.cost << " " << road.area1 << " " << road.area2 << endl;
    }

    // Search for a specific road project
    string searchId;
    cout << "\nEnter road identifier to search: ";
    cin >> searchId;
    bool found = false;

    for (int i = 0; i < roads.size(); ++i) {
        if (roads[i].identifier == searchId) {
            cout << searchId << " found at position " << i + 1 << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << searchId << " not found" << endl;
    }

    // Find the Minimum Spanning Tree (MST)
    UnionFind uf(areaMap.size());
    int totalCost = 0;
    vector<Road> mst;

    for (const Road &road : roads) {
        int u = areaMap[road.area1];
        int v = areaMap[road.area2];
        if (uf.unionSets(u, v)) {
            mst.push_back(road);
            totalCost += road.cost;
        }
    }

    // Output the MST
    cout << "\nMinimum Connection Plan (MST):" << endl;
    for (const Road &road : mst) {
        cout << road.identifier << " connects " << road.area1 << " and " << road.area2 << " with cost " << road.cost << endl;
    }
    cout << "Total Cost: " << totalCost << endl;

    return 0;
}
