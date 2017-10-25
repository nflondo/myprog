
public class DatesInYear {
	public static void main(String[] args){
		int yearIn = 2002;
//		int monthIn = 12;
		int daysInMonth;
		if (args.length > 0)
			yearIn = Integer.parseInt(args[0]);
//			monthIn = Integer.parseInt(args[0]);
//		if (args.length > 1)
//			yearIn = Integer.parseInt(args[1]);
		
		for(int month = 1; month < 13; month ++){
			daysInMonth = countDays(month, yearIn);
			for(int day = 1; day <= daysInMonth; day ++)
				System.out.println(month + "/" + day + "/" + yearIn);	
		}
//		System.out.println(monthIn + "/" + yearIn + " has "
//				+ countDays(monthIn, yearIn) + " days. ");
		
	}// main
	
	static int countDays(int month, int year){
		int count = -1;
		switch (month){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				count = 31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				count = 30;
				break;
			case 2:
				if (year %4 == 0)
					count = 29;
				else
					count = 28;
				
				if((year %100 ==0) & (year %400 != 0))
					count = 28;
		}
		return count;
	}
}
