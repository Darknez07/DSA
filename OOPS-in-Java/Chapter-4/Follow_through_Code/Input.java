import java.io.*;
class CalculatorInput{
    BufferedReader stream;
    CalculatorEngine engine;
    CalculatorInput(CalculatorEngine e){
        InputStreamReader input = new InputStreamReader(System.in);
        stream = new BufferedReader(input);
        engine = e;
    }
    public void run() throws Exception{
        for(;;){
            System.out.print("["+engine.display()+"]");
            String s = stream.readLine();
            if(s == null) break;
            if(s.length() > 0){
                char c = s.charAt(0);
                if(c == '+')  engine.add();
                else if(c == '-') engine.subtract();
                else if(c == '*') engine.multiply();
                else if(c == '/') engine.divide();
                // Answer to Q2.
                else if(c == '!') engine.factorial();
                else if(c == '^') engine.square();
                else if(c >= '0' && c <= '9') engine.digit(c - '0');
                else if(c == '=') engine.compute();
                else if(c == 'c' || c == 'C') engine.clear();
                else if(c == 'e' || c == 'E') break;
            }
        }
    }
};
public class Input{
    public static void main(String[] args) throws Exception{
        CalculatorEngine en = new CalculatorEngine();
        CalculatorInput ci = new CalculatorInput(en);
        ci.run();
    }
};