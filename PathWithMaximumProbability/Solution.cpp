#include <vector>
#include <utility>
#include <queue>

class Solution {
public:
  /*
  typedef std::vector<std::vector<std::pair<int, double>>> adjListType;
  double maxProbability(int n, std::vector<std::vector<int>>& edges, std::vector<double>& succProb, int start, int end) {
    adjListType adjList(n);
    for (int i = 0; i < edges.size(); i++) { 
      adjList[edges[i][0]].push_back(std::make_pair(edges[i][1], succProb[i]));
      adjList[edges[i][1]].push_back(std::make_pair(edges[i][0], succProb[i]));
    }

    if (adjList[start].size() == 0 || adjList[end].size() == 0) return 0;

    std::vector<bool> visited(n, false);
    std::vector<bool> globalVisited(n, false);
    std::vector<double> memo(n, -1);
    double res = dfs(visited, globalVisited, adjList, start, end, 1.0, memo);
    if (!globalVisited[start]) return 0;
    return res;
  }

  double dfs(std::vector<bool> &visited, std::vector<bool> &globalVisited, adjListType &adjList, int src, int dest, double prob, std::vector<double> &memo) {
    if (src == dest) return prob;
    if (visited[src]) return 0;
    if (memo[src] >= 0) return memo[src];

    globalVisited[src] = true;

    double res = 0;
    for (auto &i : adjList[src]) {
      visited[src] = true;
      res = std::max(res, dfs(visited, globalVisited, adjList, i.first, dest, prob * i.second, memo));
      visited[src] = false;
    }

    memo[src] = res;
    return res;
  }
  */
  
  double maxProbability(int n, std::vector<std::vector<int>>& edges, std::vector<double>& succProb, int start, int end) {
    typedef std::vector<std::vector<std::pair<int, double>>> adjListType;
    adjListType adjList(n);
    for (std::size_t i = 0; i < edges.size(); i++) { 
      adjList[edges[i][0]].push_back(std::make_pair(edges[i][1], succProb[i]));
      adjList[edges[i][1]].push_back(std::make_pair(edges[i][0], succProb[i]));
    }

    if (adjList[start].size() == 0 || adjList[end].size() == 0) return 0;

    double max = 0;
    std::queue<std::pair<int, double>> q;
    std::vector<double> maxProb(n, 0);
    q.push({start, 1.0});

    while (!q.empty()) {
      auto& [vert, prob] = q.front();
      if (vert == end) {
	max = std::max(max, prob);
      }
      else {
	maxProb[vert] = std::max(maxProb[vert], prob);
	
	for (auto& [next, nextProb] : adjList[vert]) {
	  if (prob * nextProb > maxProb[next]) {
	    q.push({next, prob * nextProb});
	  }
	}
      }
      q.pop();
    }

    return max;
  }
};
