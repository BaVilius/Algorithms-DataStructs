package com.graphImplementation;

import java.util.ArrayList;

public class Main extends GraphOperations{


    public static void main(String[] args) {
	    int verticleCount = 5;
        ArrayList<Person> adjacencyList = new ArrayList<>(verticleCount);

        adjacencyList.add(new Person('A'));
        adjacencyList.add(new Person('B'));
        adjacencyList.add(new Person('C'));
        adjacencyList.add(new Person('D'));
        adjacencyList.add(new Person('E'));

        /*
        * A:->B->C->D
        * B:->A->C
        * C:->D->E
        * D:->A->B
        * E->B
        * */

        addEdge(adjacencyList, 0, 'B');
        addEdge(adjacencyList, 0, 'C');
        //addEdge(adjacencyList, 0, 'D');
        addEdge(adjacencyList, 1, 'A');
        addEdge(adjacencyList, 1, 'C');
        addEdge(adjacencyList, 2, 'D');
        addEdge(adjacencyList, 2, 'E');
        addEdge(adjacencyList, 3, 'A');
        addEdge(adjacencyList, 3, 'B');
        addEdge(adjacencyList, 4, 'B');

        printAdjacencyList(adjacencyList);

        canExpectHelp(adjacencyList, 'B', 'B');

    }
}
