#include <vector>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
  int numIdenticalPairs(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
	if (nums[i] == nums[j]) res++;
      }
    }

    return res;
  }

  int numSub(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      while (s[i] == '0') i++;
      int j = i;
      while (j < s.size() && s[j] == '1') j++;
      res += (j - i) * (j - i + 1) / 2;
      i = j + 1;
    }

    return res;
  }

  /*
  typedef std::vector<std::vector<std::pair<int, double>>> adjListType;
  double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
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
  
  double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    typedef std::vector<std::vector<std::pair<int, double>>> adjListType;
    adjListType adjList(n);
    for (int i = 0; i < edges.size(); i++) { 
      adjList[edges[i][0]].push_back(std::make_pair(edges[i][1], succProb[i]));
      adjList[edges[i][1]].push_back(std::make_pair(edges[i][0], succProb[i]));
    }

    if (adjList[start].size() == 0 || adjList[end].size() == 0) return 0;

    double max = 0;
    std::queue<std::pair<int, double>> q;
    std::vector<double> visited(n, 0);
    q.push({start, 1.0});

    while (!q.empty()) {
      std::pair<int, double> &cur = q.front();
      if (cur.first == end) {
	max = std::max(max, cur.second);
      }
      else {
	visited[cur.first] = std::max(visited[cur.first], cur.second);
	
	for (auto &i : adjList[cur.first]) {
	  if (cur.second * i.second > visited[i.first]) {
	    q.push({i.first, cur.second * i.second});
	  }
	}
      }
      q.pop();
    }

    return max;
  }
};

int main() {
  std::vector<std::vector<int>> edges = {{2, 3}, {1, 2}, {3, 4}, {1, 3}, {1, 4}, {0, 1}, {2, 4}, {0, 4}, {0, 2}};
  std::vector<double> succProb = {0.06, 0.26, 0.49, 0.25, 0.2, 0.64, 0.23, 0.21, 0.77};
  std::cout << edges.size() << std::endl;
  std::cout << succProb.size() << std::endl;
  std::cout << Solution().maxProbability(5, edges, succProb, 0, 3) << std::endl;
}
