//******************************
// General class
//******************************

public class GenClass {
    int height, weight, depth;
    
    public GenClass (){
    
    }
    
    public void info(){
        System.out.println ("Height: " + this.height);
        System.out.println ("weight: " + weight);
        System.out.println ("depth: " + depth);    
    }
    
    public static void main(String[]args){
        
        GenClass box = new GenClass();
        box.height = 10;
        box.weight = 20;
        box.depth = 5;        
        box.info();
    
    }
}
