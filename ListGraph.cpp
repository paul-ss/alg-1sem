//
// Created by paul_s on 19.05.2020.
//

#include "ListGraph.hpp"

ListGraph::ListGraph(int count) {
  assert(count >= 0);
  _adjacencyLists.reserve(count);
  _adjacencyLists.resize(count);
}



ListGraph::ListGraph(const IGraph &graph) :
    _adjacencyLists(graph.VerticesCount()) {
  for (size_t i = 0; i < graph.VerticesCount(); i++ ) {
    auto nextVertices = graph.GetNextVertices(i);
    for (auto vertex : nextVertices) {
      _adjacencyLists[i].push_back(vertex);
    }
  }
}




void ListGraph::AddEdge(int from, int to) {
  assert(from >= 0 && from < VerticesCount());
  assert(to >= 0 && to < VerticesCount());

  _adjacencyLists[from].push_back(to);
}



int ListGraph::VerticesCount() const {
  return _adjacencyLists.size();
}



std::vector<int> ListGraph::GetNextVertices(int vertex) const {
  assert(vertex >= 0 && vertex < VerticesCount());

  std::vector<int> result;
  for (auto v : _adjacencyLists[vertex]) {
    result.push_back(v);
  }

  return result;
}


std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
  assert(vertex >= 0 && vertex < VerticesCount());

  std::vector<int> result;
  for (size_t i = 0; i < VerticesCount(); i++) {
    for (auto v : _adjacencyLists[i]) {
      if (v == vertex) {
        result.push_back(i);
      }
    }
  }

  return result;
}