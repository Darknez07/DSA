package Follow_through_Code;
class CalculatorEngine{
    int value,keep;
    char toDo;
    CalculatorEngine(){clear();}
    public void add(){binaryOperation('+');}
    public void subtract(){binaryOperation('-');}
    public void multiply(){binaryOperation('*');}
    public void divide(){binaryOperation('/');}
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
    }
    public void clear(){
        value = 0;
        keep = 0;
    }
    public void binaryOperation(char op){
        keep = value;
        value = 0;
        toDo = op;
    }
    public void digit(int x){
        if(x > 9 || x < 0){
            return;
        }else{
            value*=10;value+=x;
        }
    }
    public int display(){return (value);}
};
