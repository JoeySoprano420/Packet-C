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

const data = {
  nodes: [
    { id: "Packet1", group: 1 },
    { id: "Capsule1", group: 2 }
  ],
  links: [
    { source: "Packet1", target: "Capsule1", value: 1 }
  ]
};

const width = 600, height = 400;

const svg = d3.select("body").append("svg")
  .attr("width", width)
  .attr("height", height);

const link = svg.append("g")
  .selectAll("line")
  .data(data.links)
  .enter().append("line")
  .attr("stroke-width", 2);

const node = svg.append("g")
  .selectAll("circle")
  .data(data.nodes)
  .enter().append("circle")
  .attr("r", 10)
  .attr("fill", "blue");

d3.forceSimulation(data.nodes)
  .force("link", d3.forceLink(data.links).distance(50))
  .force("charge", d3.forceManyBody())
  .force("center", d3.forceCenter(width / 2, height / 2))
  .on("tick", function() {
    link.attr("x1", d => d.source.x)
        .attr("y1", d => d.source.y)
        .attr("x2", d => d.target.x)
        .attr("y2", d => d.target.y);

    node.attr("cx", d => d.x).attr("cy", d => d.y);
  });
