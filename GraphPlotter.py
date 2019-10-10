#!/usr/bin/env python
# coding: utf-8

# In[]:

import sys
import networkx as nx
import plotly.graph_objects as go


# In[]:


def build_edges(G):
    edge_x = []
    edge_y = []
    for edge in G.edges():
        x0, y0 = G.node[edge[0]]['pos']
        x1, y1 = G.node[edge[1]]['pos']
        edge_x.append(x0)
        edge_x.append(x1)
        edge_x.append(None)
        edge_y.append(y0)
        edge_y.append(y1)
        edge_y.append(None)
    return edge_x, edge_y


# In[]:


def build_edge_trace(G):
    edge_x, edge_y = build_edges(G)
    edge_trace = go.Scatter(
        x=edge_x, y=edge_y,
        line=dict(width=0.5, color='#888'),
        hoverinfo='none',
        mode='lines')
    return edge_trace


# In[]:


def build_nodes(G):
    node_x = []
    node_y = []
    for node in G.nodes():
        x, y = G.node[node]['pos']
        node_x.append(x)
        node_y.append(y)
    return node_x, node_y


# In[]:


def build_node_trace(G):
    node_x, node_y = build_nodes(G)

    node_trace = go.Scatter(
        x=node_x, y=node_y,
        mode='markers',
        hoverinfo='text',
        marker=dict(
            showscale=True,
            # colorscale options
            #'Greys' | 'YlGnBu' | 'Greens' | 'YlOrRd' | 'Bluered' | 'RdBu' |
            #'Reds' | 'Blues' | 'Picnic' | 'Rainbow' | 'Portland' | 'Jet' |
            #'Hot' | 'Blackbody' | 'Earth' | 'Electric' | 'Viridis' |
            colorscale='Rainbow',
            reversescale=True,
            color=[],
            size=10,
            colorbar=dict(
                thickness=15,
                title='calls',
                xanchor='left',
                titleside='right'
            ),
            line_width=2))
    return node_trace


# In[]:


def config_node_trace(G):
    node_calls = []
    node_text = []
    for nodeID in G.nodes:
        node_calls.append(G.nodes[nodeID]['calls'])
        node_text.append('vertex ID : ' + str(nodeID) + '\n# of calls: '+str(G.nodes[nodeID]['calls']))
    return node_calls, node_text


# In[]:

beginRange = 0
endRange = 10000
print(str(sys.argv))

if len(sys.argv) == 3:
    beginRange = int(sys.argv[1])
    endRange = int(sys.argv[2])
if len(sys.argv) == 2:
    endRange = int(sys.argv[1])

for state_id in range(beginRange, endRange):
    G = nx.Graph()
    fileName = "output/graph_states/graph" + str(state_id) + ".txt"
    file = open(fileName,"r")
    lines = file.readlines()
    root = -1
    for line in lines:
        line = [int(x) for x in line.replace('\n', '').split(' ')]
        if len(line) > 1:
            G.add_node(line[0], calls = line[1], pos=(line[2], line[3]))
            if len(line) > 4:
                G.add_edge(line[0], line[4])
                if len(line) > 5:
                    G.add_edge(line[0], line[5])
            else:
                root = line[0]

    edge_trace = build_edge_trace(G)
    node_trace = build_node_trace(G)
    node_trace.marker.color, node_trace.text = config_node_trace(G)

    fig = go.Figure(data=[edge_trace, node_trace],
             layout=go.Layout(
                title='<br>Estado do grafo após a requisição ' + str(state_id) + '\n',
                titlefont_size=16,
                showlegend=False,
                hovermode='closest',
                margin=dict(b=20,l=5,r=5,t=40),
                annotations=[ dict(
                    text="Python code: <a href='https://plot.ly/ipython-notebooks/network-graphs/'> https://plot.ly/ipython-notebooks/network-graphs/</a>",
                    showarrow=False,
                    xref="paper", yref="paper",
                    x=0.005, y=-0.002 ) ],
                xaxis=dict(showgrid=False, zeroline=False, showticklabels=False),
                yaxis=dict(showgrid=False, zeroline=False, showticklabels=False))
                )
    #fig.show()
    fileName = "output/graph_plots/graph" + str(state_id) + ".png"
    fig.write_image(fileName)
    file.close();


# In[ ]:
