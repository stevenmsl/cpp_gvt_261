#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol261;
using namespace std;

/*takeaways
  - use DFS
    - no node should be visited twice
  - don't forget to check if every single node is visited

*/
bool Solution::_visit(int node, int from, vector<vector<int>> &g, vector<bool> &v)
{
  /* node has been visited - the in-degree is more than one
     - it's not a tree
  */
  if (v[node])
    return false;
  v[node] = true;
  for (auto n : g[node])
  {
    /* exclude the node you are visiting from */
    if (n == from)
      continue;
    if (!_visit(n, node, g, v))
      return false;
  }
  return true;
}

bool Solution::validTree(int n, vector<pair<int, int>> &edges)
{
  auto g = vector<vector<int>>(n);
  for (auto &[from, to] : edges)
    g[from].push_back(to), g[to].push_back(from);
  auto visited = vector<bool>(n, false);

  if (!_visit(0, -1, g, visited))
    return false;

  /* make sure the graph is connected -
  every node must be visited */

  for (auto v : visited)
    if (!v)
      return false;

  return true;
}