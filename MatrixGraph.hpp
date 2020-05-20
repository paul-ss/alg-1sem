//
// Created by paul_s on 19.05.2020.
//

#pragma once
#include <cassert>
#include "IGraph.hpp"


class MatrixGraph : public IGraph {
public:
  MatrixGraph(int count);
  MatrixGraph(const IGraph &graph);

  void AddEdge(int from, int to);
  int VerticesCount() const;
  std::vector<int> GetNextVertices(int vertex) const;
  std::vector<int> GetPrevVertices(int vertex) const;

private:
  std::vector<std::vector<int>>  _adjacencyMatrix;
};