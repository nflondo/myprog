package com.prefect.ecommerce;
import java.util.*;

public class Item implements Comparable {
	private String id;
	private String name;
	private double retail;
	private int quantity;
	private double price;
	private boolean noDiscount;

	Item(String idIn, String nameIn, String retailIn, String quanIn, boolean noDiscIn){
		id = idIn;
		name = nameIn;
		retail = Double.parseDouble(retailIn);
		quantity = Integer.parseInt(quanIn);
		noDiscount = noDiscIn;
		
		if (noDiscount == true)
			price = retail;
		else if (quantity > 400)
			price = retail * .5D;
		else if (quantity > 200)
			price = retail * .6D;
		else
			price = retail * .7D;
		
		price = Math.floor(price * 100 + .5) / 100; // rounds off to two or fewer decimal points
					
	}
	
	public int compareTo(Object obj){
		Item temp = (Item)obj;
		if (this.price < temp.price)
			return 1;
		else if (this.price > temp.price)
			return -1;
		return 0;		
	}
	
	// Accessor methods are needed because the vars are private
	public String getId(){
		return id;
	}
	public String getName(){
		return name;
	}
	public double getRetail(){
		return retail;
	}
	public int getQuantity(){
		return quantity;
	}
	public double getPrice(){
		return price;
	}
	

} // end Item class
