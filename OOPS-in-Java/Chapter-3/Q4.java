class Square_draw{
    int side;
    Square_draw(int l){side = l;}
    public void enlargeSquare(int x){side+=x;}
    public int computeArea(){return side*side;}
    public void DrawWithStars(){
        for(int i=0;i<side;i++){
            for(int j=0;j<side;j++){
                if(i == 0 || i == (side - 1) || j == 0 || j == (side - 1))
                    System.out.print("*");
                else
                    System.out.print(" ");
            }
            System.out.println();
        }
    }
    public void DrawWithMultiPlus(){
        for(int i=0;i<side;i++){
            for(int j=0;j<side;j++){
                if(i == 0 || i == (side - 1) || j == 0 || j == (side - 1))
                    System.out.print("X");
                else
                    System.out.print("+");
            }
            System.out.println();
        }
    }
};
public class Q4{
    public static void main(String[] args) {
        Square_draw sqd = new Square_draw(3);
        System.out.println(sqd.computeArea());
        sqd.DrawWithStars();
        sqd.enlargeSquare(2);
        sqd.DrawWithStars();
        sqd.DrawWithMultiPlus();
    }
}
