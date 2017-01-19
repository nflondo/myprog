package com.prefect.ecommerce;

import java.util.*;

public class Storefront {
	private LinkedList catalog = new LinkedList();
	
	public void addItem(String id, String name, String price, String quant){
		
		Item it = new Item(id, name, price, quant);
		catalog.add(it);
	}
	
	public Item getItem(int i){
		return (Item)catalog.get(i);
		
	}
	
	public int getSize(){
		return catalog.size();
	}

	//Sorts a linked list and other data structures based on the natural sort order
	//of the objects they contain, calling the object's compareTo() method to determine
	//this order.
	public void sort(){
		Collections.sort(catalog);
	}
}
