# Combine all the steps into a single code block for generating the BLE relationship diagram

import matplotlib.pyplot as plt
import networkx as nx

# Create a directed graph
G_requested = nx.DiGraph()

# Add nodes with their descriptions

G_requested.add_node("Peripheral Device\n(GATT Server)", description="(e.g., Smart Bulb)\n- Broadcasts Data")
G_requested.add_node("Central Device 1\n(GATT Client)", description="(e.g., Smartphone)")
G_requested.add_node("Central Device 2\n(GATT Client)", description="(e.g., Tablet)")
G_requested.add_node("Service 1", description="- Light Control\n")
G_requested.add_node("Service 2", description="- Device Info\n")
G_requested.add_node("Characteristic 1.1", description="- Brightness\n- Read/Write")
G_requested.add_node("Characteristic 1.2", description="- Color\n- Read/Write")
G_requested.add_node("Characteristic 2.1", description="- Manufacturer\n- Read-only")

# Add edges to indicate relationships
G_requested.add_edge("Central Device 1\n(GATT Client)", "Peripheral Device\n(GATT Server)", relation="Connects to")
G_requested.add_edge("Central Device 2\n(GATT Client)", "Peripheral Device\n(GATT Server)", relation="Connects to")
G_requested.add_edge("Peripheral Device\n(GATT Server)", "Service 1", relation="Provides")
G_requested.add_edge("Peripheral Device\n(GATT Server)", "Service 2", relation="Provides")
G_requested.add_edge("Service 1", "Characteristic 1.1", relation="Contains")
G_requested.add_edge("Service 1", "Characteristic 1.2", relation="Contains")
G_requested.add_edge("Service 2", "Characteristic 2.1", relation="Contains")

# Manually specify the positions to avoid overlapping
pos_manual = {
    "Peripheral Device\n(GATT Server)": (0, 0),
    "Central Device 1\n(GATT Client)": (-1, 1),
    "Central Device 2\n(GATT Client)": (1, 1),
    "Service 1": (-0.5, -1),
    "Service 2": (0.5, -1),
    "Characteristic 1.1": (-1, -2),
    "Characteristic 1.2": (0, -2),
    "Characteristic 2.1": (1, -2),
}

# Define colors for different types of nodes
node_colors = {
    "Peripheral Device\n(GATT Server)": 'lightblue',
    "Central Device 1\n(GATT Client)": 'lightblue',
    "Central Device 2\n(GATT Client)": 'lightblue',
    "Service 1": 'lightgreen',
    "Service 2": 'lightgreen',
    "Characteristic 1.1": 'lightcoral',
    "Characteristic 1.2": 'lightcoral',
    "Characteristic 2.1": 'lightcoral',
}
plt.figure(figsize=(9, 6))

# Draw nodes and edges with the manual layout and different colors
nx.draw(G_requested, pos_manual, with_labels=True, 
        node_color=[node_colors[node] for node in G_requested.nodes], 
        node_size=3000, font_size=10, font_color='black', font_weight='bold', 
        arrows=True)

# Draw edge labels with the manual layout
edge_labels_requested = nx.get_edge_attributes(G_requested, 'relation')
nx.draw_networkx_edge_labels(G_requested, pos_manual, edge_labels=edge_labels_requested)

# Add updated descriptions as annotetions with the manual layout
for node, (x, y) in pos_manual.items():
    description = G_requested.nodes[node]['description']
    plt.text(x, y - 0.4, s=description, horizontalalignment='center', fontsize=9)

# Show updated plot with the manual layout and different colors
plt.title('BLE (Bluetooth Low Energy)')
plt.axis('off')

plt.subplots_adjust(left=0.1, right=0.9, bottom=0.1, top=0.9)

plt.savefig("BLE_Relationships.png",  dpi=500)

plt.show()
