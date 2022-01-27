import networkx as nx
import numpy as np
import matplotlib.pyplot as plt

graph = nx.Graph()

input = np.loadtxt("C:\\dev\\labs_local\\3_semester\\lab3\\visualization\\matrix.txt", dtype='i', delimiter=' ')

for i in range(input.shape[0]):
    for j in range(input.shape[1]):
        if i is not j:
            if input[i][j] > 0:
                graph.add_edge(i, j)

nx.draw(graph, with_labels=True, font_weight='bold')
plt.show()