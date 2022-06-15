
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol261
{

  class Solution
  {
  private:
    bool _visit(int node, int from, vector<vector<int>> &g, vector<bool> &v);

  public:
    bool validTree(int n, vector<pair<int, int>> &edges);
  };
}
#endif