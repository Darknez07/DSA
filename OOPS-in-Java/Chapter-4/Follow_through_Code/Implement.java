public class Implement {
    public static void main(String[] args) {
        CalculatorEngine c = new CalculatorEngine();
        c.digit(3);
        c.digit(4);
        c.digit(5);
        System.out.println(c.display());
        c.clear();
        c.digit(4);
        c.digit(5);
        // The result is 155 which we don't want
        // We really don't want the two digit number in as
        // digit
        System.out.println(c.display());
        c.add();
        c.digit(3);
        c.digit(2);
        System.out.println(c.display());
        c.compute();
        System.out.println(c.display());
    }
}
