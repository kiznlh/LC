#include <bits/stdc++.h>
using namespace std;

// Modified UnionFind data structure.
class Relation {
 public:
  explicit Relation(int size) : base_(size), ranks_(size) {
    for (int i = 0; i < size; ++i) {
      base_[i] = {i, 1.0};
    }
  }

  // Find(x) returns [x0, ratio] such that $x = ratio * $x0.
  pair<int, double> Find(int x) {
    pair<int, double>& base = base_[x];
    if (base.first != x) {
      auto [x0, ratio] = Find(base.first);
      base.first = x0;
      base.second *= ratio;
    }
    return base;
  }

  void Add(int x, double ratio, int y) {
    auto [x0, ratio_x] = Find(x);
    auto [y0, ratio_y] = Find(y);
    if (x0 == y0) {
      return;  // We must have ratio_x = ratio_y * ratio in this case.
    }
    if (ranks_[x0] < ranks_[y0]) {
      // Now we have ratio_x * x0 = ratio * ratio_y * y0
      // => x0 = ratio * ratio_y / ratio_x y0
      base_[x0] = {y0, ratio * ratio_y / ratio_x};
    } else if (ranks_[x0] > ranks_[y0]) {
      base_[y0] = {x0, ratio_x / ratio_y / ratio};
    } else { // same rank
      ++ranks_[y0];
      base_[x0] = {y0, ratio * ratio_y / ratio_x};
    }
  }

 private:
  vector<pair<int, double>> base_;
  vector<int> ranks_;
};

class IdGen {
 public:
  // The argument `string_view` must not point to temporary strings.
  int GetId(string_view v) {
    int& id = lookup_[v];
    if (id == 0) {
      id = ++id_counter_;
    }
    return id;
  }

  int max() const { return id_counter_; }

 private:
  int id_counter_ = 0;
  unordered_map<string_view, int> lookup_;
};

class Solution {
public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                              vector<vector<string>>& queries) {
    IdGen id_gen;
    Relation relation(equations.size() * 2 + 1);
    for (int i = 0; i < equations.size(); ++i) {
      const vector<string>& equation = equations[i];
      int a = id_gen.GetId(equation[0]);
      int b = id_gen.GetId(equation[1]);
      relation.Add(a, values[i], b);  // $a == values[i] * $b
    }
    const int max_id = id_gen.max();

    vector<double> results(queries.size(), -1.0);
    for (int i = 0; i < queries.size(); ++i) {
      const vector<string>& query = queries[i];
      int c = id_gen.GetId(query[0]);
      if (c > max_id) {
        continue;
      }
      int d = id_gen.GetId(query[1]);
      if (d > max_id) {
        continue;
      }
      // $c = ratio_c * $c0
      auto [c0, ratio_c] = relation.Find(c);
      // $d = ratio_d * $d0
      auto [d0, ratio_d] = relation.Find(d);
      if (c0 != d0) {
        continue;
      }
      // Therefore we get $c / $d.
      results[i] = ratio_c / ratio_d;
    }
    return results;
  }
};