//
// Created by paul_s on 19.05.2020.
//

#pragma once
#include "IGraph.hpp"

#include <cassert>
#include <set>


class SetGraph : public IGraph {
public:
  SetGraph(int count);
  SetGraph(const IGraph &graph);

  void AddEdge(int from, int to);
  int VerticesCount() const;
  std::vector<int> GetNextVertices(int vertex) const;
  std::vector<int> GetPrevVertices(int vertex) const;

private:
  std::vector<std::multiset<int>>  _adjacencySets;
};
