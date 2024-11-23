const data = {
  nodes: [
    { id: "Packet1", group: 1 },
    { id: "Capsule1", group: 2 }
  ],
  links: [
    { source: "Packet1", target: "Capsule1", value: 1 }
  ]
};

d3.forceSimulation(data.nodes)
  .force("link", d3.forceLink(data.links).distance(100))
  .force("charge", d3.forceManyBody())
  .force("center", d3.forceCenter(width / 2, height / 2));
