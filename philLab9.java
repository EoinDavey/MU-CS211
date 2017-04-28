import java.util.*;

public class Graph{
    public static void main(String[] args){
        Scanner myscanner = new Scanner(System.in);
        int size=myscanner.nextInt();
        int[][] array = new int[size][size];
        for(int i=0;i<size;i++){ //load up the data into array
            for(int j=0;j<size;j++){
                array[i][j]=myscanner.nextInt();
            }
        }
        int furthestdistance=0; //keep track of the longest path found so far
        String furthestroute=""; 
        for(int i=0;i<size;i++){ //loop through all possible starting positions
            int visited=0; //how many vertices have been visited so far?
            Vertex[] vertices = new Vertex[size]; //initiate the
            vertex objects
            for(int j=0;j<size;j++){
                vertices[j]=new Vertex(""+(char)(97+i));
            }
            vertices[i].visited=true; //we visit the starting position
            visited++; //we've visited one vertex so far
            vertices[i].distance=0; //set this vertex as starting point
            for(int j=0;j<size;j++){ //update distances from starting point
                if(array[j][i]>0){ //only update those that can be reached from here
                    vertices[j].distance=array[j][i];
                }
            } 
            while(visited<size){ //while not all vertices visited
                int minvalue=Integer.MAX_VALUE; //set to infinity as default-there must be something shorter
                int minvertex=-1; //a default which will crash if it is not superseded
                for(int j=0;j<size;j++){ //find the next vertex to visit
                    if(vertices[j].visited==false){ //if it has not been visited
                        if(vertices[j].distance<minvalue){
                            minvalue=vertices[j].distance;
                            minvertex=j; //we are choosing the
                            closest vertex to the starting position which has not been visited yet
                        }
                    }
                }
                vertices[minvertex].visited=true; //we have now visited it
                visited++;
                for(int j=0;j<size;j++){ //update distances from this new point
                    if(array[j][minvertex]>0&&vertices[j].visited==false){ //if vertex is connected and not visited
                        if(vertices[j].distance>vertices[minvertex].distance+array[j][minvertex]){ 
                            vertices[j].distance=vertices[minvertex].distance+array[j][minvertex];
                            //update if a new shorter route to this vertex has been found
                            vertices[j].route=minvertex; //track the path taken
                        }
                    }
                }
            } 
            for(int x=0;x<size;x++){ //check for a new record distance
                if(vertices[x].distance>furthestdistance){ //go through all distances in the graph
                    furthestdistance=vertices[x].distance;
                    int visiting=x;
                    String solution=""; //build up the path taken to get this particular record beating distance
                    while(visiting>=0){ //the starting position has route of -1
                        solution=vertices[visiting].label+""+solution;
                        visiting=vertices[visiting].route; //step back along the route generating this distance
                    }
                    solution=vertices[i].label+""+solution; //this is the starting position
                    furthestroute=solution; //keep track of this record path
                }
            }
        }
        System.out.println(furthestdistance); //print out the results
    }
}
class Vertex{ //everything you need for a vertex
    public boolean visited=false; //has it been visited?
    int distance=Integer.MAX_VALUE; //the shortest route from starting position to this vertex
    int route=-1; //keep track of the last step taken to reach this vertex for the shortest path - what vertex did it come from?
    String label; //name of the vertex
    public Vertex (String labelin){ //give the vertex a name when
        instantiated
        label=labelin;
    }
}
