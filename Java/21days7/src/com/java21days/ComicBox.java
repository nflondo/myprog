/*
 * 
 */
package com.java21days;

/**
 *
 * @author nmunoz
 */
public class ComicBox {
   class InnerComic {
       String title;
       String issueNumber;
       String condition;
       float basePrice;
       float price;
       
       InnerComic(String inTitle, String inIssueNumber, String inCondition,
               float inBasePrice) {
           title = inTitle;
           issueNumber = inIssueNumber;
           condition = inCondition;
           basePrice = inBasePrice;
       }
       
       void setPrice(float factor){
           price = basePrice * factor
       }
   } // innerComic class
   
   public ComicBox(){
       HashMap<String, Float> quality = new HashMap<>();
       float price1 = 3.00F;
       quality.put("mint", price1);
       float price2 = 2.00F;
       quality.put("near mint", price2);
       float price3 = 1.50F;
       quality.put("Very fine", price3);
       float price4 = 1.00F;
       quality.put("fine", price4);
       float price5 = 0.50F;
       quality.put("good", price5);
       float price6 = 0.25F;
       quality.put("poor", price6);
       InnerComic[] comix = new InnerComic[3];
       comix[0] = new InnerComic("Amazing Spider-Man", "1A", "very fine,"
               + "12_000.00F");
       comix[0].setPrice(quality.get(comix[0].condition));
       comix[1] = new InnerComic("Incredible Hulk", "181", "near mint", 680.00F);
       comix[1].setPrice(quality.get(comix[1].condition
       comix[2] = new InnerComic("Cerebus", "1A", "good", 190.00F);
       comix[2].setPrice(quality.get(comix[2].condition));
   }
}
