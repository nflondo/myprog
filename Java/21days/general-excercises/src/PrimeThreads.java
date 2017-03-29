
public class PrimeThreads {
	public static void main(String[] args) {
		PrimeFinder[] finder = new PrimeFinder[args.length];
		for (int i = 0; i < args.length; i++){
			try{
				long count = Long.parseLong(args[i]);
				finder[i] = new PrimeFinder(count);
				System.out.println("Looking for prime " + count);
			} catch (NumberFormatException nfe){
				System.out.println("Error " + nfe.getMessage());
			}
			
		} //for
		boolean complete = false;
		while (!complete) {
			complete = true;
			for (int j = 0; j < finder.length; j++){
				if (!finder[j].finished)
					complete = false;
			} //for
			try {
				Thread.sleep(1000);
			}catch (InterruptedException ie){
				// Do nothing
			}
		}
		for (int j = 0; j < finder.length; j++){
			System.out.println("Prime " + finder[j].target + " is: " 
					+ finder[j].prime);
		}
	} // main

} // class
