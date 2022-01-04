class Square{
    int l;
    public Square(int len){l = len;}
    public void enlargeSquare(int x){l+=x;}
    public int computeArea(){return l*l;}
};
public class Q2{
    public static void main(String[] args){
        Square sq = new Square(7);
        sq.enlargeSquare(2);
        System.out.println(sq.computeArea());
    }
}