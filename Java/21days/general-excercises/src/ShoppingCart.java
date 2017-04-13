import java.util.*;
/***
 * Uses a vector as a shopping cart that holds fruit objects * 
 * @author nmunoz
 *
 */

public class ShoppingCart {

	public static void main(String[] args) {
		// TODO Auto-generated method stu
		Fruit mango = new Fruit("mango", 2, 4.00F);
		Fruit pear = new Fruit("pear", 4, 5.00F);
		Fruit apple = new Fruit("apple", 6, 6.00F);
		
		Vector cart = new Vector();
		cart.addElement(mango);
		cart.addElement(pear);
		cart.addElement(apple);
		
		for (int i = 0; i < cart.size(); i++){
			Fruit temp = (Fruit) cart.elementAt(i);
			System.out.print("Name: " + temp.name);
			System.out.print(" Quantity: " + temp.quantity);
			System.out.println(" Price: " + temp.price);
		}
		
		/* Another way of doing it instead of for loop:
		 *  Iterator it = cart.iterator();
        while (it.hasNext()) {
            Fruit fr = (Fruit)it.next();
            System.out.println(fr.name+ ", " + (fr.quantity*fr.price));
		 */
		
		
	}
	
}

class Fruit{
	String name;
	int quantity;
	float price;
	
	public Fruit(String inName, int inQuantity, float inPrice){
		name = inName;
		quantity = inQuantity;
		price = inPrice;
		
	}
}
