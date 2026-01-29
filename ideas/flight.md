# Unintended Flight Unnattendence
In Iliffe Airport there are n flight attendants not in airplanes, but instead clacking away at their keyboards, focused on clearing customer requests. Alongside them are n customers calling out to gain their attention. Each customer has a series of disjoint ranges of times that they will be calling for help, however no one will answer them unless you break a flight attendant's focus.

Once a second you may break a flight attendant's focus and direct them towards a "nearby" customer that is currently calling for help. Each customer is "nearby" some subset of the flight attendants. After a customer and flight attendant are united, they will be in conversation for the remaining time and will be unable to accept more requests/call for help.

What is the maximum number of conversations you can form between customers and flight attendants within the first t seconds?

# Solution
Create nodes c_{in} and c_{out} for each customer and connect them by an edge. Form a bipartite graph by connecting each flight attendant to a c_{in} if the corresponding customer is nearby the flight attendant. Create t nodes for each second in the experiment and connect a c_{out} to t_{i} if that customer is calling for help during the i^{th} second. Connect all flight attendants to the source and all t nodes to the sink. All edges are capacity 1.

Only one conversation can be formed per second and this is limited by the capacity one edge from t nodes to the sink. Likewise a flight attendant can only be in one conversation which is limited by the capacity one edges from the source.  A customer can also only be in one conversation which is limited by the capacity one edge between c_{in} and c_{out} (without these in and out nodes two flight attendants could talk to the same customer on different seconds). A conversation is a path from source to sink through a flight attendant, customer nodes and t node. Computing the max flow on this network will output the maximum number of conversations. 

There should be O(n^2) edges if customers and t are O(n). With Edmonds Karp this is O(Ef) = O(n^3), but I'm not really sure how worst case analysis works with max flow problems. According to the slides the worst case almost never occurs?    

To complicate this question you could make it so that conversations last one second, and flight attendants can have multiple conversations within the first t seconds (still only one conversation a second). I think you would only need to make the edge capacities between source and flight attendants infinity to answer this. I wonder if you could make conversations last some variable number of seconds, or have each flight attendant have their own individual rate that they can answer questions. Seems tricky.

