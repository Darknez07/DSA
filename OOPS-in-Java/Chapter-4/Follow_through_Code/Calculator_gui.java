import java.awt.*;
import java.awt.event.*;
class CalculatorFrame extends Frame implements ActionListener{
    CalculatorEngine engine;
    TextField display;
    WindowListener listener = new WindowAdapter() {
        public void windowClosing(WindowEvent e){System.exit(0);}
    };
    CalculatorFrame(CalculatorEngine e){
        super("Calculator");
        Panel top,bottom; Button b;
        engine = e;
        top = new Panel();
        top.add(display = new TextField(20));
        bottom = new Panel();
        bottom.setLayout(new GridLayout(4,4));
        int j = 0;
        String sgn[] = {"+","-","*"};
        for(int i=1;i<=9;i++){
            bottom.add(b = new Button(Integer.toString(i)));
            b.addActionListener(this);
            if(i % 3 == 0){
                bottom.add(b = new Button(sgn[j]));
                b.addActionListener(this);
                j++;
            }
        }
        bottom.add(b = new Button("C"));b.addActionListener(this);
        bottom.add(b = new Button("0"));b.addActionListener(this);
        bottom.add(b = new Button("="));b.addActionListener(this);
        bottom.add(b = new Button("/"));b.addActionListener(this);
        // Factorial,Power of 2
        bottom.add(b = new Button("!"));b.addActionListener(this);
        bottom.add(b = new Button("^"));b.addActionListener(this);
        bottom.add(b = new Button("E"));b.addActionListener(this);
        bottom.add(b = new Button("N"));b.addActionListener(this);
        setLayout(new BorderLayout());
        add("North",top);
        add("South",bottom);
        addWindowListener(listener);
        setSize(200, 200);
        setVisible(true);
    }
    public void actionPerformed(ActionEvent e){
        char ch = e.getActionCommand().charAt(0);
        if(ch == '+') engine.add();
        else if(ch == '-') engine.subtract();
        else if(ch == '*') engine.multiply();
        else if(ch == '/') engine.divide();
        // Integration of the event into
        // the code
        else if(ch == '!') engine.factorial();
        else if(ch == '^') engine.square();
        else if(ch >= '0' && ch <= '9') engine.digit(ch - '0');
        else if(ch == '=') engine.compute();
        else if(ch == 'c' || ch == 'C') engine.clear();
        else if(ch == 'E' || ch == 'e') System.exit(0);
        display.setText(Integer.toString(engine.display()));
    }
    public static void main(String[] args) {
        new CalculatorFrame(new CalculatorEngine());
    }
}
