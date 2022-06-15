#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol261;

/*
Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true
*/

tuple<int, vector<pair<int, int>>, bool>
testFixture1()
{
  auto input = vector<pair<int, int>>{{0, 1}, {0, 2}, {0, 3}, {1, 4}};
  return make_tuple(5, input, true);
}

/*
Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
*/

tuple<int, vector<pair<int, int>>, bool>
testFixture2()
{
  auto input = vector<pair<int, int>>{{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
  return make_tuple(5, input, false);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;

  cout << "Expect to see : " << get<2>(f) << endl;
  cout << sol.validTree(get<0>(f), get<1>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  Solution sol;

  cout << "Expect to see : " << get<2>(f) << endl;
  cout << sol.validTree(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}