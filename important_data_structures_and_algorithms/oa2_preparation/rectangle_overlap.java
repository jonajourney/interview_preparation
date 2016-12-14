
public class Solution{
    public boolean overlap(Node topLeftA, Node bottomRightA, Node topLeftB, Node bottomRightB){
        if(topLeftA.y < bottomRightB.y || topLeftB.y < bottomRightA.y){
            return false;
        }

        if(topLeftA.x > bottomRightB.x || topLeftB.x > bottomRightA.x){
            return false;
        }
    }

    public static class Node{
        double x;
        double y;
        public Node(double x, double y){
            this.x = x;
            this.y = y;
        }
    }
}