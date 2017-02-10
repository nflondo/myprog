package com.prefect.ecommerce;
import java.util.*;

/*
 * Manages a collection of products in an online store.  Each product is an Item object, and they are stored
 * in a LinkedList instance variable called "catalog"
 */

public class Storefront {
	private LinkedList catalog = new LinkedList();
	
	public void addItem(String id, String name, String price, String quant){
		
		Item it = new Item(id, name, price, quant);
		catalog.add(it);  // linkedlist add method
	}
	
	public Item getItem(int i){
		return (Item)catalog.get(i);
		
	}
	
	// Returns number of objects in the catalog
	public int getSize(){
		return catalog.size();
	}

	//The Class Method Collections.sort sorts a linked list and other data structures based on the natural 
	//sort order of the objects they contain, calling the object's compareTo() method to determine
	//this order.
	public void sort(){
		Collections.sort(catalog);
	}
}
