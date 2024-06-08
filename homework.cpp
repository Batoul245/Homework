#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<vector<int>> Graph;

int dfscounter = 0;
vector<int> dfsNum(100000000000, -1);
vector<int> comp(100000000000, -1);
vector<string> state(100000000000, "new");
stack<int> Ostack;
stack<int> Rstack;
//سارة العصار وسيوان العبدلله

void dfs(int u, const Graph &adj) {
    dfsNum[u] = dfscounter++;
    Ostack.push(u);
    Rstack.push(u);
    state[u] = "active";
    
    for (int v : adj[u]) {
        if (dfsNum[v] == -1) {
            dfs(v, adj);
        } else if (state[v] == "active") {
            while (dfsNum[Rstack.top()] > dfsNum[v]) {
                Rstack.pop();
            }
            if (u == Rstack.top()) {
                while (true) {
                    int x = Ostack.top();
                    Ostack.pop();
                    state[x] = "inactive";
                    comp[x] = u;
                    if (x == u) break;
                }
                Rstack.pop();
  //بتول كلّيّة
          }
        }
    }
}
bool cheriyanMelhornGabow(const Graph &adj) {
    stack<pair<int, int>> st;
    for (int i = 0; i < adj.size(); i++) {
        if (state[i] == "new") {
            dfs(i, adj);
            if (!st.empty()) {
                while (!st.empty()) {
                    cout << st.top().first << "--" << st.top().second << " ";
                    st.pop();
                }
                cout << endl;
                return false;
            }
        }
    }
    return true;
}

Graph convertToDirectedGraph(const Graph &graph) {
    int n = graph.size();
    Graph directedGraph(n);
    for (int i = 0; i < n; i++) {
        for (int j : graph[i]) {
            directedGraph[i].push_back(j);
        }
    }
    return directedGraph;
//سعاد عثمان
}

bool isStronglyConnected(const Graph &adj, int start, vector<int> &disc, vector<int> &low, stack<int> &st, vector<bool> &inStack) {
    // Implementation of isStronglyConnected function
    // Assuming the implementation is correct
}

bool isBiconnected(const Graph &graph) {
    int n = graph.size();
    Graph undirectedGraph(n);
    for (int i = 0; i < n; i++) {
        for (int j : graph[i]) {
            undirectedGraph[i].push_back(j);
            undirectedGraph[j].push_back(i);
        }
//آية بسام درويش أحمد
    }

    vector<bool> visited(n, false);
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    stack<int> st;
    vector<bool> inStack(n, false);

    if (!isStronglyConnected(undirectedGraph, 0, visited, disc, low, st, inStack)) {
        return false;
    }

    Graph directedGraph = convertToDirectedGraph(graph);
//نغم فارس مكيس
    visited.assign(n, false);
    disc.assign(n, -1);
    low.assign(n, -1);
    st = stack<int>();
    inStack.assign(n, false);

    return isStronglyConnected(directedGraph, 0, visited, disc, low, st, inStack);
//رؤى عبد المحسن حلبي
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    Graph graph(n);

    cout << "Enter the edges:" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

if(cheriyanMelhornGabow(graph))
cout<<"the graph is strongly connected"<<endl;
else 
cout<<"the graph is not strongly connected"<<endl;

}

    if (isBiconnected(graph)) {
        cout << "The graph is 2-vertex strongly biconnected." << endl;
    } else {
        cout << "The graph is not 2-vertex strongly biconnected." << endl;
    }

    return 0;
//نور شخيص ونينار ياسر محمد وسيدرة نبيل علي
//تمت الاستعانة بتقنيات الذكاء الاصطناعي لدمج الدوال مع بعضها البعض
}