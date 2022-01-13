class CalculatorEngine{
    int value,keep;
    char toDo;
    boolean done;
    CalculatorEngine(){clear();}
    // Q1 and Q2 factorial is below
    public int fact(int n){return n <= 1 ? 1:n*fact(n - 1); }
    public void add(){binaryOperation('+');}
    public void subtract(){binaryOperation('-');}
    public void multiply(){binaryOperation('*');}
    public void divide(){binaryOperation('/');}
    // New functions for Q1 and Q2
    public void factorial(){toDo = '!';value = fact(value);}
    public void square(){toDo = '^';value*=value;}
    public void compute(){
        if(toDo == '+')
            value+=keep;
        else if(toDo == '-')
            value = keep - value;
        else if(toDo == '*')
            value*=keep;
        else if(toDo == '/')
            value = keep/value;
        keep = 0;
        done = true;
    }
    public void clear(){
        value = 0;
        keep = 0;
        done = false;
    }
    public void binaryOperation(char op){
        keep = value;
        value = 0;
        toDo = op;
    }
    public void digit(int x){
        if(done){
            value = 0;
            done  = false;
        }
        if(x > 9 || x < 0){
            return;
        }else{
            value*=10;value+=x;
        }
    }
    public int display(){return (value);}
};
