import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class ZipCode {
	private int zipCode;
	
	public ZipCode(String zipCodeIn){
		setZipCode(zipCodeIn);
		
	}
	public void setZipCode(String zipCodeIn){
		// enforce 5 digits
		 Pattern pattern = Pattern.compile("\\d{5}");
		 Matcher matcher = pattern.matcher(zipCodeIn);

	      if (matcher.matches()) {
	    	  System.out.println("Valid");
	    	  zipCode = Integer.parseInt(zipCodeIn);
	      }
	      else
	      {
	    	  System.out.println("zip code must be in the form XXXXXXX");
	      }
		 
				
	}
	public int getZipCode(){
		return zipCode;
		
	}
	public static void main(String[] args){
		ZipCode entry = new ZipCode("84097");
		System.out.println("entry: " + entry.getZipCode());
		
	}
	
		
}
