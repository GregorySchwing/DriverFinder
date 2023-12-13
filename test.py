#!/usr/bin/env python3

import helloWorldModule

result = helloWorldModule.hello(name="world")
assert(result==42)

import networkx
print(networkx.__version__)
import networkx as nx

G = nx.karate_club_graph()
nx_native_matching = nx.max_weight_matching(G,maxcardinality=True)
print("Networkx matching len",len(nx_native_matching))
print("Networkx matching",nx_native_matching)
print("Networkx matching type",type(nx_native_matching))

sparse = nx.to_scipy_sparse_array(G,format="csr")
matching = []
result = helloWorldModule.hello2(sparse.indptr.tolist(),sparse.indices.tolist(), matching)
print(matching)

