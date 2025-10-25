This repository documents my practical learning of fundamental algorithms like Dijkstra, A*, Flood Fill, and DFS with insights, issues faced, and improvements.

 Dijkstra’s Algorithm — Shortest path in weighted graphs.
- A* Search — Optimized pathfinding using heuristics.
- Flood Fill — Used for area filling or maze traversal.
- Depth First Search — Exploring graphs by going as deep as possible.
- Breadth First Search — Layer-wise graph traversal.


### Dijkstra’s Algorithm
- Realized how priority queues (min-heaps) reduce time complexity.
- Understood the concept of relaxing edges.
- problem  between  understanding. "visited" and "final shortest distance" — (little clear)

### A* Search
- Learned about heuristic functions — tried both Euclidean and Manhattan distances.
- Discovered how overestimating heuristics breaks optimality.


### Flood Fill
- Understandingrecursion stack limits and how to convert it into iterative DFS-(still learning)
- Learned its application in image segmentation and  grid-based games.

### Depth First Search
- Saw how backtracking naturally emerges from recursion.(a new topic )
- Got tripped up by infinite loops before marking visited nodes properly.(we should be careful with every point we move forward)


Learning these algorithms showed me how simple logical steps can grow into complex systems that almost seem to think on their own. Each algorithm — whether it’s the recursive depth of DFS or the elegant precision of A* — feels like a small piece of the larger puzzle of intelligence.
Working with Arduino and sensors added another layer of understanding: algorithms don’t live in isolation. They interact with real-world noise, imperfect data, and hardware quirks. Watching code move motors, respond to light, or follow a path made abstract ideas real.
This journey wasn’t just about coding or circuits — it was about learning how logic, patience, and curiosity connect theory to reality. The deeper I went, the clearer it became that intelligence isn’t just about algorithms or machines — it’s about the human drive to build, test, fail, and try again until it works.

some new terms i came across was weighted both positive and negative how on basis of that pid moves right or left
2nd - how bfs and dfs are differnt from each other ,bfs is used  for speed and as where dfs is used where w e require backtracking like many end points
also learned about pid all the three terms how the whol emeachanism is dependen upon ki kp kd
how specificall we have to tune the values
so it doesnot over flow