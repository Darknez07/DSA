public class Q3 {
    public static void main(String[] args) {
        Square[] obs = new Square[10];
        for(int i=0;i<10;i++)
            obs[i] = new Square((int)(Math.random()*50));
        System.out.println();
        for(int i=0;i<10;i++){
            System.out.print("Area of Square "+(i+1)+" is: ");
            System.out.println(obs[i].computeArea());
        }
    }
}
