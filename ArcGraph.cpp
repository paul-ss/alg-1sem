//
// Created by paul_s on 19.05.2020.
//

#include "ArcGraph.hpp"



ArcGraph::ArcGraph(int count) {
  assert(count >= 0);
  _count = count;
}



ArcGraph::ArcGraph(const IGraph &graph) :
    _count(graph.VerticesCount()) {
  for (size_t i = 0; i < graph.VerticesCount(); i++ ) {
    auto nextVertices = graph.GetNextVertices(i);
    for (auto vertex : nextVertices) {
      _adjacencyPairs.emplace_back(i, vertex);
    }
  }
}




void ArcGraph::AddEdge(int from, int to) {
  assert(from >= 0 && from < VerticesCount());
  assert(to >= 0 && to < VerticesCount());

  _adjacencyPairs.emplace_back(from, to);
}



int ArcGraph::VerticesCount() const {
  return _count;
}



std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
  assert(vertex >= 0 && vertex < VerticesCount());

  std::vector<int> result;
  for (auto &pair : _adjacencyPairs) {
    if (pair.first == vertex) {
      result.push_back(pair.second);
    }
  }

  return result;
}


std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
  assert(vertex >= 0 && vertex < VerticesCount());

  std::vector<int> result;
  for (auto &pair : _adjacencyPairs) {
    if (pair.second == vertex) {
      result.push_back(pair.first);
    }
  }

  return result;
}