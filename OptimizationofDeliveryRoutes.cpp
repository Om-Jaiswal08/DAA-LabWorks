#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846
struct Location {
string name;
double lat, lon;
Location(string n, double la, double lo) :
name(n), lat(la), lon(lo) {}
};
double haversine(double lat1, double lon1,
double lat2, double lon2) {
const double R = 6371.0;
double latDist = (lat2 - lat1) * M_PI / 180.0;
double lonDist = (lon2 - lon1) * M_PI / 180.0;
double a = sin(latDist / 2) * sin(latDist / 2) +
cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI
/ 180.0) *
sin(lonDist / 2) * sin(lonDist / 2);
double c = 2 * atan2(sqrt(a), sqrt(1 - a));
return R * c;
}
vector<int> bellmanFord(int V, const
vector<vector<int>>& edges, int src) {
const int INF = 1e9;
vector<int> dist(V, INF);
dist[src] = 0;

for (int i = 0; i < V; i++) {
for (auto &edge : edges) {
int u = edge[0];
int v = edge[1];
int wt = edge[2];

if (dist[u] != INF && dist[u] + wt < dist[v]) {
if (i == V - 1) return {-1};
dist[v] = dist[u] + wt;
}
}
}
return dist;
}

int main() {
srand(time(0));

vector<Location> locations = {
{"Zero Mile (Depot)", 21.1458, 79.0882},
{"Sitabuldi", 21.1491, 79.0820},
{"Dhantoli", 21.1376, 79.0888},
{"Civil Lines", 21.1505, 79.0715},
{"Sadar Bazaar", 21.1621, 79.0803},
{"Ganeshpeth", 21.1331, 79.1040},
{"Seminary Hills", 21.1640, 79.0515}
};

int V = locations.size();
vector<vector<int>> edges;
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
if (i != j) {
double dist = haversine(locations[i].lat,
locations[i].lon,
locations[j].lat,
locations[j].lon);

double trafficFactor = 1.0 +
(static_cast<double>(rand()) / RAND_MAX) * 0.5;
int weightedDistance =
static_cast<int>(round(dist * trafficFactor));
edges.push_back({i, j,
weightedDistance});
}
}
}

int src = 0;
vector<int> distances = bellmanFord(V, edges,
src);
cout << "Shortest distances from " <<
locations[src].name << ":\n";
const int INF = 1e9;
for (int i = 0; i < V; i++) {
cout << "To " << left << setw(20) <<
locations[i].name << ": ";

if (distances[i] == INF)
cout << "Unreachable\n";
else
cout << distances[i] << " km\n";
}

return 0;
}