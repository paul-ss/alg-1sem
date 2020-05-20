//
// Created by paul_s on 19.05.2020.
//

#include "SetGraph.hpp"



SetGraph::SetGraph(int count) {
  assert(count >= 0);
    _adjacencySets.reserve(count);
    _adjacencySets.resize(count);
}



SetGraph::SetGraph(const IGraph &graph) :
    _adjacencySets(graph.VerticesCount()) {
  for (size_t i = 0; i < graph.VerticesCount(); i++ ) {
    auto nextVertices = graph.GetNextVertices(i);
    for (auto vertex : nextVertices) {
      _adjacencySets[i].insert(vertex);
    }
  }
}




void SetGraph::AddEdge(int from, int to) {
  assert(from >= 0 && from < VerticesCount());
  assert(to >= 0 && to < VerticesCount());

  _adjacencySets[from].insert(to);
}



int SetGraph::VerticesCount() const {
  return _adjacencySets.size();
}



std::vector<int> SetGraph::GetNextVertices(int vertex) const {
  assert(vertex >= 0 && vertex < VerticesCount());

  std::vector<int> result;
  for (auto v : _adjacencySets[vertex]) {
    result.push_back(v);
  }

  return result;
}


std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
  assert(vertex >= 0 && vertex < VerticesCount());

  std::vector<int> result;
  for (size_t i = 0; i < VerticesCount(); i++) {
    for (auto v : _adjacencySets[i]) {
      if (v == vertex) {
        result.push_back(i);
      }
    }
  }

  return result;
}