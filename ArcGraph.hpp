//
// Created by paul_s on 19.05.2020.
//

#pragma once
#include "IGraph.hpp"

#include <cassert>


class ArcGraph : public IGraph {
public:
  ArcGraph(int count);
  ArcGraph(const IGraph &graph);

  virtual void AddEdge(int from, int to);
  virtual int VerticesCount() const;
  virtual std::vector<int> GetNextVertices(int vertex) const;
  virtual std::vector<int> GetPrevVertices(int vertex) const;

private:
  std::vector<std::pair<int,int>> _adjacencyPairs;
  int _count;
};
