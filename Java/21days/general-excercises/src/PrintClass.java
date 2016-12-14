
public class PrintClass {
	int x = 0;
	int y = 1;
	
	void printMe(){
		System.out.println("x is" + x + ", y is" + y);
		System.out.println("I am an instace of the class " + this.getClass().getName());
		
	}
	
} // End PrintClass

class PrintSubClass extends PrintClass{
	int z = 3;
	
	void printMe(){
		//System.out.println("x is: " + x + ", y is: " + y + ", z is: " + z);
		//System.out.println("I am an instace of the class " + this.getClass().getName());
		super.printMe();
		System.out.println("z is: " + z);
		
	}
	public static void main(String[]args){
		
		PrintSubClass obj = new PrintSubClass();
		obj.printMe();
		
	}
		
}
