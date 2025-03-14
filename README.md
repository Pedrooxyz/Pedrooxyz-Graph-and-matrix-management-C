# Graph-and-matrix-management-C-language-
This project, written in the C language, was created in the academic context of Advanced Data Structures, taken at the Polytechnic Institute of Cávado and Ave. The project is focused on implementing and testing fundamental operations for manipulating graphs and matrices, with the aim of improving skills in Data Structures. 

# Problem to solve
I was asked to create a solution capable of creating and manipulating graphs, also using concepts taught in class and exploring others. To do this, functions were formulated to create vertices, graph adjacencies and a function to create the graph itself. Insertion and removal functions for vertices and edges were also formulated. After the initial definition of the data structure, the functions for manipulating it were then created. A function was formulated for loading data from a file, a graph, path-finding functions using the DFT algorithm, a function responsible for calculating the sum of the values of the vertices on a given path. Finally, a function was created that provides the path or paths that give the greatest possible sum of the integers, returning the sum itself.

# Objectives
The main objective of this work was to improve the understanding of advanced data structures through practice, particularly exploring the development and management of graphs. To achieve this goal, the following concrete objectives were defined: defining and implementing data structures, developing functions, loading graphs from files, finding paths, calculating sums of paths and identifying paths.

# Report Review

## C Language

The C programming language is a high-level language, just like PASCAL, COBOL, BASIC, etc. "As for C, what area of development is it intended for? The answer is - none in particular. It is what is usually called general purpose, and this is one of its great advantages, as it adapts to the development of any project, such as operating systems, graphic interfaces, log processing, etc. Incredibly, C is also used to write the compilers for other languages" [1].

## Advanced Data Structures

Before understanding what advanced data structures are, it is first necessary to understand what data structures are. "Data structures is how we store and access data. A data structure design consists of 1) the data organization, 2) an optional index, and 3) the algorithms that support basic operations (e.g., put, get, update). All algorithms deal with data and most often their design starts by defining a data structure that will minimize computation and data movement. Effectively, the possible ways to design an algorithm (and whole data systems) are restricted by the data structure choices. For example, we can only utilize an optimized sorted search algorithm if the data is sorted and if we can maintain the data efficiently in such a state." [2]. This means that data structures determine how we store and access information. We also realize that choices of data structures restrict the design possibilities of algorithms. 

Advanced data structures are essential for solving problems in computing. There are several types of advanced data structures, for example, trees, hash tables, heaps, graphs, etc. These structures allow for the efficient organization and manipulation of large volumes of data. What are dynamic data structures? They are data structures that are not limited in terms of size, and are often exploited in advanced scenarios to optimize operations such as searching, inserting and deleting data (e.g. linked lists).

## Graphs

"A graph 𝐺 is a set of vertices 𝑉(𝐺) and a set of edges 𝐸(𝐺), where each edge connects two vertices. Graphs are used to model pairwise relations between objects. Graph theory has various applications in computer science, biology, transport networks, and social science, among others." [3]. In short, graphs are a data structure that represents relationships between objects. As mentioned, they are made up of vertices and edges that connect vertices. Among the characteristics of graphs are that they can be oriented or unoriented, i.e. there can be a connection from A to B and not from B to A, and that they can be weighted or unweighted, i.e. the edges between vertices have weight or not. Graph theory is widely studied due to its application in various areas, such as computer networks, transportation systems, etc. Graphs can be represented, for example, by adjacency matrices.

## Adjacency matrices

Adjacency matrices are widely used to represent graphs in table form, due to the fact that they compact and simplify the information in a graph. In an adjacency matrix, each row and column corresponds to a vertex of the graph. If there is an edge that connects the vertices represented by the corresponding rows and columns, the corresponding element in the adjacency matrix is filled in with a value that indicates this connection, usually 1 if the weights of the edges or the weight associated with the edge itself are not shown. If there is no connection between the vertices, the corresponding element in the matrix will be zero.

## Graph traversal

In Advanced Data Structures, particularly graphs, traversal is possible. This brings several advantages in terms of graph analysis. It is an extremely important process that allows you to visit all the vertices and edges of a graph. The most common traversal algorithms are depth-first search (DFS) and breadth-first search (BFS). DFS is particularly useful for problems that involve exploring all the paths in a graph, such as comparing paths for a specific purpose. BFS, on the other hand, is effective for finding the shortest path in graphs. Understanding and correctly implementing these algorithms is fundamental to solving problems involving graphs.

## Graph preservation

Graph preservation involves techniques responsible for maintaining the integrity and properties of a graph during, mainly, insertion and removal operations of vertices and edges. It is important to ensure that manipulation operations do not introduce inconsistencies or structural errors. One of the techniques for preserving graphs is also to make backups of them, for example by using export functions for files.
