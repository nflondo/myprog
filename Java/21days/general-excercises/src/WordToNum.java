
public class WordToNum {
	public static void main(String[] args){
//		int yearIn = 2002;
//		int monthIn = 12;
		String number; 
		int index = 0;
		while (index < args.length){
//		if (args.length > 0)
//			yearIn = Integer.parseInt(args[0]);
//			number = args[0];
//			monthIn = Integer.parseInt(args[0]);
//		if (args.length > 1)
//			yearIn = Integer.parseInt(args[1]);
		
//		for(int month = 1; month < 13; month ++){
//			daysInMonth = countDays(month, yearIn);
//			for(int day = 1; day <= daysInMonth; day ++)
//				System.out.println(month + "/" + day + "/" + yearIn);	
//		}
		System.out.println(args[index] + " is equal to " + 
				convertNumber(args[index]));
		index++;
		}// while loop
		
	}// main
	
	static long convertNumber(String number){
		long num = -1;
		switch (number){
			case "one":
				num = 1;
				break;
			case "two":
				num = 2;
				break;
			case "three":
				num = 3;
				break;
			case "four":
				num = 4;
				break;
			case "five":
				num = 5;
				break;
			
		}
		return num;
	}
}
