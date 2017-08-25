
public class HalfLoop {
	public static void main(String[] args){
		int[] denver = { 1500006, 18810000, 20752110 };
		int[] philadelphia = { 15020000, 18708000, 21348000 };
		int[] total = new int[denver.length];
		int sum = 0;
		
		for (int i = 0; i < denver.length; i++){
			total[i] = denver[i] + philadelphia[i];
			System.out.println((i + 1993) + " production: " + total[i]);
			sum += total[i];
		} // for
		
		System.out.println("Average production: " + (sum / denver.length));
	} // main
}
