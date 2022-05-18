package com.graphImplementation;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Stack;

public class GraphOperations {

    public static HashSet<Character> visited = new HashSet<>();

    public static void addEdge(ArrayList<Person> adjacencyList, int node, char pointsTo) {
        adjacencyList.get(node).neighbors.add(pointsTo);
        return;
    }

    public static boolean canExpectHelp(ArrayList<Person> adjacencyList, char who, char fromWho) {
        if(who == fromWho){
            System.out.println("Faulty input");
            return false;
        }
        int index = dfs(adjacencyList, who);

        for (int i = 0; i < adjacencyList.get(index).neighbors.size(); i++) {
            // this is who helped main index
            char neighbor = adjacencyList.get(index).neighbors.get(i);
            if (neighbor == fromWho) {
                System.out.println(who + " can expect to get money from " + fromWho);
                return true;
            }
            // this is who helped the helpers of the main index
            int layer2Index = findPerson(adjacencyList, neighbor);
            for (int ii = 0; ii < adjacencyList.get(layer2Index).neighbors.size(); ii++) {
                if(adjacencyList.get(layer2Index).neighbors.get(ii) == fromWho){
                    System.out.println(who + " can expect to get money from " + fromWho +
                            " ,because "+ who + " helped " + adjacencyList.get(index).neighbors.get(i) +
                            " and " + adjacencyList.get(index).neighbors.get(i) + " helped " + fromWho);
                    return true;
                }
            }
        }
        System.out.println( who +" cannot expect to get money from " + fromWho);
        return false;
}

    public static int dfs(ArrayList<Person> adjacencyList, char toLookFor){
        Stack<Character> stack = new Stack<>();

        stack.push(adjacencyList.get(0).key); // push the first element;
        visited.add((adjacencyList.get(0).key));

        while(!stack.isEmpty()){
            char current = stack.pop();
            int index = findPerson(adjacencyList, current);

            if(adjacencyList.get(index).key == toLookFor){
                return index;
            }

            for(int i = 0; i < adjacencyList.get(index).neighbors.size(); i++){
                if(!visited.contains((adjacencyList.get(index).neighbors.get(i)))){
                    stack.push(adjacencyList.get(index).neighbors.get(i));
                    visited.add(adjacencyList.get(index).neighbors.get(i));
                }
            }
        }
        return -1;
    }

    public static void printAdjacencyList(ArrayList<Person> adjacencyList){
        for(int i = 0; i < adjacencyList.size(); i++){
            System.out.print(adjacencyList.get(i).key + " : ");
            for(int ii = 0; ii < adjacencyList.get(i).neighbors.size(); ii++){
                System.out.print("->" + adjacencyList.get(i).neighbors.get(ii));
            }
            System.out.println(" ");
        }
    }
    /// function to find the index of a given linked list that is represented by a key
    public static int findPerson(ArrayList<Person> adjacencyList, char key){
        for(int i = 0; i < adjacencyList.size(); i++){
            if(adjacencyList.get(i).key == key){
                return i;
            }
        }
        throw new IllegalArgumentException("No such person found");
    }

    public static void findHelpers(ArrayList<Person> adjacencyList, char key){
        int index = findPerson(adjacencyList, key);
        for(int i = 0; i < adjacencyList.get(index).neighbors.size(); i++){
            char neighbor = adjacencyList.get(index).neighbors.get(i);
            int layer2Index = findPerson(adjacencyList, neighbor);
            for(int ii = 0; ii <adjacencyList.get(layer2Index).neighbors.size(); ii++){
                System.out.print(adjacencyList.get(layer2Index).neighbors.get(ii));
            }
            System.out.println("\n");

        }

    }

}
