#!/usr/bin/env python3

import helloWorldModule

result = helloWorldModule.hello(name="world")
assert(result==42)

import networkx
print(networkx.__version__)
import networkx as nx

G = nx.karate_club_graph()
sparse = nx.to_scipy_sparse_array(G,format="csr")
print(sparse)
print(len(sparse.indices))
print(sparse.indices)
print(len(sparse.indptr))
print(sparse.indptr)
result = helloWorldModule.hello2(sparse.indptr.tolist(),sparse.indices.tolist())

